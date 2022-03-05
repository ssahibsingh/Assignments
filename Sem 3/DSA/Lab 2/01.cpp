// even positioned elements should be greater than the odd positioned
#include <bits/stdc++.h>
using namespace std;

void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void rearrange(int arr[], int n)
{
    sort(arr, arr + n);
    int arr2[n];
    int s = 0, e = n - 1;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
            arr2[i] = arr[e--];
        else
            arr2[i] = arr[s++];
    }
    cout << "Rearranged Array: ";
    display_arr(arr2, n);
}


int main()
{
    int arr[50] = {}, n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    rearrange(arr, n);
}