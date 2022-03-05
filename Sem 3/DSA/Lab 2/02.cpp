#include <iostream>
using namespace std;
void zero_end(int *arr, int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}
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

    zero_end(arr, n);

    arr[0] = 2 * arr[0];

    cout << "Modified Array: ";
    display_arr(arr, n);
}