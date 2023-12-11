#include <bits/stdc++.h>
using namespace std;

int piv (int arr[], int a, int b)
{
	int pivot = arr[b];
	int k=a-1;
	for (int j=a;j<=(b-1);j++)
	{
		if (arr[j] < pivot)
		{
			k++;
			int h=arr[k];
			arr[k]=arr[j];
			arr[j]=h;
		}
	}

	int h=arr[k+1];
	arr[k+1]=arr[b];
	arr[b]=h;
	return k+1;
}

void qsort(int arr[], int a, int b)
{
	if (a<b)
	{
		int k = piv(arr,a,b);
		qsort(arr,a,k-1);
		qsort(arr,k+1,b);
	}
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
		cin>>arr[i];
	qsort(arr,0,n-1);
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	return 0;
}
