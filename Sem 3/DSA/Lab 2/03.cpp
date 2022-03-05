#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the number k: ";
    cin >> k;

    int sma_count = 0;
    for (int j = 0; j < n; j++)
        if (arr[j] <= k)
            sma_count = sma_count + 1;

    int lar_count = 0;
    for (int i = 0; i < sma_count; i++)
        if (arr[i] > k)
            lar_count++;

    int count = lar_count;
    for (int i = 0, j = sma_count; j < n; i++, j++)
    {
        if (arr[i] > k)
            lar_count--;
        if (arr[j] > k)
            lar_count++;
        count = min(count, lar_count);
    }
    cout << "Minimum possible switches: " << count << endl;
    return 0;
}