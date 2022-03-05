// Insert Element at given position
#include <iostream>
using namespace std;

void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int *insert(int n, int arr[], int ele, int pos)
{
    n++;
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = ele;
    return arr;
}

int main()
{
    int arr[100] = {0}, ele, pos, n = 10;
    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;
    cout << "Initial Array: ";
    display_arr(arr, n);
    cout << "Enter element end its position: ";
    cin >> ele >> pos;
    insert(n, arr, ele, pos);
    cout << "Resulted Array: ";
    display_arr(arr, n);
    return 0;
}