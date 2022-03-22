#include <iostream>
using namespace std;

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int *arr, int left, int mid, int right)
{
    int i, j, k;
    int left_length = mid - left + 1;
    int right_length = right - mid;
    int left_array[left_length];
    int right_array[right_length];

    for (i = 0; i < left_length; i++)
        left_array[i] = arr[left + i];
        
    for (j = 0; j < right_length; j++)
        right_array[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = left;

    while (i < left_length && j < right_length)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < left_length)
    { 
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_length)
    { 
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right)
{
    int mid;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Elements: ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    cout<<"\nUnsorted Array: ";
    displayArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout<<"Sorted Array: \t";
    displayArray(arr, n);
    
}