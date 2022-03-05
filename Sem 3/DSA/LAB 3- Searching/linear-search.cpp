#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
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


	int res = linear_search(arr, n, x);
	
	if (res == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << res;

	return 0;
}
