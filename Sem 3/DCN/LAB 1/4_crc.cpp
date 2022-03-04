#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

char exor(char a, char b) // XOR operation
{
    if (a == b)
        return '0';
    else
        return '1';
}

char * getCRC(char data[], char key[])
{
    int data_length = strlen(data);
    int key_length = strlen(key);
    int result_length = data_length + key_length - 1; // Resultant Length After appending extra zeroes
    char step_divident[20], remainder[20];


    for (int i = 0; i < key_length - 1; i++) // Appending n-1 zeroes to data
        data[data_length + i] = '0';
    data[result_length] = '\0';


    for (int i = 0; i < key_length; i++)
        remainder[i] = data[i]; 

    for (int j = key_length; j <= result_length; j++)
    {
        for (int i = 0; i < key_length; i++)
            step_divident[i] = remainder[i]; // remainder of previous step is step_divident of current step

        if (remainder[0] == '0') // shifting the remainder by 1 bit if first bit of remainder is 0
            for (int i = 0; i < key_length - 1; i++)
                remainder[i] = step_divident[i + 1];
        else // else performing XOR operation on Step Divident and Key
            for (int i = 0; i < key_length - 1; i++)
                remainder[i] = exor(step_divident[i + 1], key[i + 1]);

        if (j != result_length)
            remainder[key_length - 1] = data[j]; // appending next bit of data to remainder obtained by division
        else
            remainder[key_length - 1] = '\0';
    }
    for (int i = 0; i < key_length - 1; i++)
        data[data_length + i] = remainder[i]; // replacing n-1 zeros with remainder's n-1 bits i.e. CRC
    data[result_length] = '\0';

    cout <<"CRC: " << remainder <<endl;
    return data;
}

int main()
{
    char key[20], data[20];
    cout << "Enter Data: ";
    cin >> data;
    cout << "Enter Key (divisor): ";
    cin >> key;


    cout<<endl<<"Sender Side"<<endl;
    char *data_sent = getCRC(data, key);

    cout<<"Data Transmitted: "<< data_sent <<endl;

    cout<<"Receiver Side"<<endl;
    getCRC(data_sent, key);

    cout<<"No Error Found"<<endl;

    
    return 0;
}