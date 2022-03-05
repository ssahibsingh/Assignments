// Delete element at given position
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
    int ele;
    
    cout << "Initial Array: ";
    display_arr(arr, n);

    cout << "Enter Element to Delete: ";
    cin >> ele;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            for (int j = i; j < (n - 1); j++)
                arr[j] = arr[j + 1];
            i--;
            n--;
        }
    }
    cout << "Resulted Array: ";
    display_arr(arr, n);
    return 0;
}