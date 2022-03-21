#include <iostream>
using namespace std;
 
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n)
{
    
    int ele;
    for (int i = 1; i < n; i++)
    {
        ele = arr[i];
        int j = i - 1;
 
        while (j >= 0 && arr[j] > ele)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = ele;
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

    insertionSort(arr, n);

    cout<<"Sorted Array: \t";
    displayArray(arr, n);
    
    return 0;
}