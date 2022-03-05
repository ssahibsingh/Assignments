#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] > x)
            return binary_search(arr, l, m - 1, x);

        return binary_search(arr, m + 1, r, x);
    }

    return -1;
}

int main(void)
{
    int x, n;
    cout << "Enter Array Size: ";
    cin >> n;

    int arr[n];
    cout << "Enter Elements of Array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Enter Element you want to search: ";
    cin >> x;

    int res = binary_search(arr, 0, n - 1, x);
    if (res == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << res;
    return 0;
}
