#include <iostream>
using namespace std;
#define MAX 100

int *carryone(int arr[], int segments) // function to handle the last carry one
{
    int i;
    for (i = 0; i < segments - 1; i++)
        arr[i] = 0;

    arr[i] = 1;
    return arr;
}

int *binarysum(int seg1[], int seg2[], int segments) // Function for performing Binary Sum
{
    int carry = 0, i;
    int *d = new int[MAX];

    for (i = segments - 1; i >= 0; i--)
    {
        if (seg1[i] == 1 && seg2[i] == 1 && carry == 0)
        {
            d[i] = 0;
            carry = 1;
        }
        else if (seg1[i] == 1 && seg2[i] == 1 && carry == 1)
        {
            d[i] = 1;
            carry = 1;
        }
        else if (seg1[i] == 0 && seg2[i] == 0 && carry == 0)
        {
            d[i] = 0;
            carry = 0;
        }
        else if (seg1[i] == 0 && seg2[i] == 0 && carry == 1)
        {
            d[i] = 1;
            carry = 0;
        }
        else if (seg1[i] == 1 && seg2[i] == 0 && carry == 0)
        {
            d[i] = 1;
            carry = 0;
        }
        else if (seg1[i] == 1 && seg2[i] == 0 && carry == 1)
        {
            d[i] = 0;
            carry = 1;
        }
        else if (seg1[i] == 0 && seg2[i] == 1 && carry == 0)
        {
            d[i] = 1;
            carry = 0;
        }
        else if (seg1[i] == 0 && seg2[i] == 1 && carry == 1)
        {
            d[i] = 0;
            carry = 1;
        }
        else
            break;
    }
    if (carry == 1)
    {
        d = carryone(d, segments);
    }
    return d;
}

int *complement(int *arr1, int segments)
{
    for (int i = 0; i < segments; i++)
    {
        if (arr1[i] == 0)
            arr1[i] = 1;
        else
            arr1[i] = 0;
        cout << arr1[i];
    }
    return arr1;
}

int *sender(int bits, int *arr1)
{
    int seg1[MAX], seg2[MAX], segments;

    segments = bits / 2;
    cout << "\nSENDER" << endl;
    cout << "Message: ";
    for (int i = 0; i < bits; i++)
        cout << arr1[i];

    // Segmenting the data in 2 segments
    for (int i = 0; i < segments; i++)
        seg1[i] = arr1[i];

    int j = 0;
    for (int i = segments; i < bits; i++)
    {
        seg2[j] = arr1[i];
        j++;
    }

    // Displaying Segements
    cout << "\nSegments: " << endl;
    cout << " Segment 1: ";
    for (int i = 0; i < segments; i++)
        cout << seg1[i];

    cout << "\n Segment 2: ";
    for (int i = 0; i < segments; i++)
        cout << seg2[i];

    int *sum;
    sum = binarysum(seg1, seg2, segments);
    cout << "\n\nBinary Sum: ";
    for (int i = 0; i < segments; i++) // Displaying Binary Sum
        cout << sum[i];

    cout << endl;
    cout << "Complement of Sum = Check Sum = ";
    int *checksum = complement(sum, segments); // Displaying Checksum
    return checksum;
}

int *receiver(int bits, int *arr1, int *checksum)
{
    int seg1[MAX], seg2[MAX], segments, flag = 1;
    segments = bits / 2;

    // Segmenting the data in 2 segments
    for (int i = 0; i < segments; i++)
        seg1[i] = arr1[i];

    int j = 0;
    for (int i = segments; i < bits; i++)
    {
        seg2[j] = arr1[i];
        j++;
    }

    cout << "\n\nRECEIVER: \n";
    int *sum = binarysum(checksum, binarysum(seg1, seg2, segments), segments); // performing binary sum of checksum and data received
    cout << "Sum of Received Segments: ";
    for (int i = 0; i < segments; i++){
        cout << sum[i];
        if(sum[i]!=1)
            flag = 0;
        
    }
    if(flag == 1)
        cout << "\nReceived Message is correct with no Error." << endl;
    else
        cout<<"There is an Error in the Received Message."<<endl;

    return sum;
}

int main()
{
    int bits, arr1[MAX];
    cout << "Enter Number of Bits: ";
    cin >> bits;

    if (bits % 2 != 0) 
    {
        cout << "Enter Even Bit Number\n"
             << endl;
        main();
    }

    cout << "Enter Data: " << endl;
    for (int i = 0; i < bits; i++)
        cin >> arr1[i];

    int *checksum = sender(bits, arr1); // Displaying Sender Side
    receiver(bits, arr1, checksum); // Displaying Receiver Side

    return 0;
}