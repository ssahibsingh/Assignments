#include <iostream>
#include <cstring>
using namespace std;

int getParity(string s)
{
    int ones = 0;

    for (int i = 0; i < s.length(); i++) // calculating no. of ones for Parity Bit
        if (s[i] == '1')
            ones++;

    if (ones % 2 == 0)
        return 0;
    else
        return 1;
}

string dataTransmitted(string s, int parityBit)
{
    s.insert(0, to_string(parityBit)); // inserting parity bit at start
    return s;
}

void sender(string s, int parityBit)
{
    cout << "\nSENDER SIDE" << endl;
    cout << "Data Transmitted: " << dataTransmitted(s, parityBit) << endl; //displaying the Transmitted Data
}

void receiver(string receiverData)
{
    cout << "\nRECEIVER SIDE" << endl;
    cout << "Data Received: " << receiverData << endl;
    int parityBit = getParity(receiverData); // calculating parity bit of the data received
    if (int(receiverData[0]) != parityBit) 
        cout << "Received Message is correct with no Error." << endl;
    else
        cout << "There is an Error in the Received Message." << endl;
}

int main()
{
    string s;
    cout << "Enter the Data: ";
    cin >> s;
    cout << "Data Entered: " << s << endl; //displaying the Data Entered

    int parityBit = getParity(s); // calculating parity bit for Entered Data
    string receiverData = dataTransmitted(s, parityBit);

    sender(s, parityBit); // sender side
    receiver(receiverData); // receiver side

    return 0;
}