#include <iostream>
using namespace std;
int* mergearrays(int *temp,int temp1[],int temp2[],int n,int len1,int len2)
{
	//int temp[n];
	int a=0,b=0,k=0;
	while(a!=len1  && b!=len2)
	{
		if(temp1[a] <=temp2[b]) temp[k++] = temp1[a++];
		else temp[k++] = temp2[b++];
	}
	while(a!=len1)
		temp[k++] = temp1[a++];
	while(b!=len2)
		temp[k++] = temp2[b++];
	return temp;
}
void merge(int** arr,int lowr,int lowc,int highr, int highc)
{
	if(lowc != highc) 
	{
		int n =highc-lowc+1;
		int p=0;
		if(n%2==0) p=n/2;
		else p =n/2+1;
		int temp1[p];
		int temp2[n/2];
		int *temp= new int;
		
		int mid = (highc+lowc)/2;
		for(int i=lowr;i<=highr;i++)
		{
			int k=0,l=0;
			for(int j=lowc;j<=mid;j++)
			{
				temp1[k++] = arr[i][j];
			}
			for(int j=mid+1;j<=highc;j++)
			{
				temp2[l++] = arr[i][j];
			}
			temp=mergearrays(temp,temp1,temp2,n,p,n/2);
			for(int a=lowc;a<=highc;a++)
			{
				arr[i][a] = temp[a-lowc];
			}
		}
	}
	
	
	if(lowr != highr) 
	{
		int n =highr-lowr+1;
		int p=0;
		if(n%2==0) p=n/2;
		else p =n/2+1;
		int temp1[p];
		int temp2[n/2];
		int *temp= new int;
		
		int mid = (highr+lowr)/2;
		for(int i=lowc;i<=highc;i++)
		{
			int k=0,l=0;
			for(int j=lowr;j<=mid;j++)
			{
				temp1[k++] = arr[j][i];
			}
			for(int j=mid+1;j<=highr;j++)
			{
				temp2[l++] = arr[j][i];
			}
			temp=mergearrays(temp,temp1,temp2,n,p,n/2);
			for(int a=lowr;a<=highr;a++)
			{
				arr[a][i] = temp[a-lowr];
			}
		}
	}
}
void mergesort(int** arr,int lowr, int lowc, int highr, int highc,int m,int n)
{
	if(lowr==highr && lowc==highc) return;
	if((lowr+highr)/2 < m && (lowc+highc)/2 <n)
		mergesort(arr,lowr,lowc,(lowr+highr)/2,(lowc+highc)/2,m,n);
	if((lowc+highc)/2+1 < n && (lowr+highr)/2 <m)
		mergesort(arr,lowr,(lowc+highc)/2+1,(lowr+highr)/2,highc,m,n);
	if((lowr+highr)/2+1 < m && (lowc+highc)/2 <n )
		mergesort(arr,(lowr+highr)/2+1,lowc,highr,(lowc+highc)/2,m,n);
	if((lowr+highr)/2+1 <m && (lowc+highc)/2+1 <n)
		mergesort(arr,(lowr+highr)/2+1,(lowc+highc)/2+1,highr,highc,m,n);
	merge(arr,lowr,lowc,highr,highc);
}

int main() {
	
	int m,n;
	cin>>m>>n;
	int **a;
	a = new int *[m];
		for(int i = 0; i <m; i++)
		    a[i] = new int[n];
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}

    mergesort(a,0,0,m-1,n-1,m,n);
    for(int i=0;i<m;i++)
	   for(int j=0;j<n;j++)
	        cout<<a[i][j]<<" ";
	return 0;
}
