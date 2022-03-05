// Selection sort

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void sort(int arr[], int n)
{
    int min_ele_index;
    for (int i = 0; i < n - 1; i++)
    {
        min_ele_index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_ele_index])
                min_ele_index = j;
        swap(&arr[min_ele_index], &arr[i]);
    }
}

int main()
{
    int arr[] = {78, 10, 15, 89, 65, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    cout << "Sorted array: ";
    display_arr(arr, n);
    return 0;
}