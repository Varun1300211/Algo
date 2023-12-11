#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int x)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(arr[mid] == x)
			return mid;
		else if(arr[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int x;
	cin>>x;
	cout<<BinarySearch(arr, n, x);
    return 0;
}
