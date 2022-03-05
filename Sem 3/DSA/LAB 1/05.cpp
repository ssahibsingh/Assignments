// traverse an array, print all elements and find sum of elements at even index

#include <iostream>
using namespace std;
void even_sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i += 2)
        sum += arr[i];
    cout << "Sum of array elements at even indices: " << sum << endl;
}

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
    int sum = 0;
    cout << "Array: ";
    display_arr(arr, n);
    even_sum(arr, n);
    return 0;
}