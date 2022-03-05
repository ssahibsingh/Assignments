#include <bits/stdc++.h>
using namespace std;

void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int n, arr[n];
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    cout << "Largest Element: " << arr[n - 1] << endl;
}