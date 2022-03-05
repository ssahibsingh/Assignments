// largest and smallest element
#include <iostream>
using namespace std;

void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int arr[] = {78, 10, 15, 89, 65, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0], max = arr[0];
    cout << "Array: ";
    display_arr(arr, n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }
    cout << "Largest: " << max << "\nSmallest: " << min;
}