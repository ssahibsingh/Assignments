#include <bits/stdc++.h>
using namespace std;
 
void hammingDistance(int n1, int n2)
{
    int x = n1 ^ n2;
    int ones = 0;
 
    // Calculating Number of Ones in XOR of n1 and n2
    while (x > 0) {
        ones += x & 1;
        x >>= 1;
    }
 
    cout<<"Hamming Distance: "<<ones<<endl;
}
 
int main()
{
    int n1, n2;
    cout<<"Enter two Numbers to find Hamming distance: "<<endl;
    cin>>n1>>n2;
    hammingDistance(n1, n2); // Displaying Hamming Distance
    return 0;
}