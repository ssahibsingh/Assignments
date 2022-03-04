#include <iostream>
#include <string>
using namespace std;

void getData(char arr[][8]) // getting data from the user
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            cin >> arr[i][j];
}

void display(char arr[][8])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << arr[i][j];
        cout << "\t";
    }
}

void LRC(char arr[][8])
{
    int lrc[8];
    int n = 0;
    for (int i = 0; i < 8; i++) // calculating LRC
    {
        int ones = 0;
        for (int j = 0; j < 4; j++)
            if (arr[j][n] == '1')
                ones++;

        if (ones % 2 == 0)
            lrc[i] = 0;
        else
            lrc[i] = 1;
        n++;
    }

    cout<<endl<<"Sender Side"<<endl;
    cout<<"LRC: ";
    // displaying LRC
    for (int i = 0; i < 8; i++)
        cout << lrc[i];

    cout << endl;
    
    // displaying data transmitted
    cout << "Data Transmitted: " << endl;
    display(arr);
    for (int i = 0; i < 8; i++)
        cout << lrc[i];

    
    cout<<endl<<"\nReceiver Side"<<endl;
    cout<<"Parity Bit of Received Data: ";
    for (int i = 0; i < 8; i++)
        cout << lrc[i];

    cout<<endl<<"No Error Found";
}

int main()
{
    char arr[4][8];

    cout << "Enter Data: " << endl;
    getData(arr);

    
    LRC(arr);

    return 0;
}