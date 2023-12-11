#include<bits/stdc++.h>
using namespace std;
void p(int arr[][3], int str, int stc, int d)
{
	int k;
	for(k=1;k<=arr[0][2];k++)
	{
		while(arr[k][0]==str)
		{
			if(arr[k][1]==stc)
			{
				cout<<arr[k][0]<<"   "<<arr[k][1]<<"   "<<arr[k][2]<<"   "<<d<<endl;
				break;
			}
		}
	}
}
int main()
{
	int n,m,non,stc,str,i,d,x,k;
	d=k=1;
	cin>>n;
	cin>>m;
	cin>>non;
	int arr[non+1][3];
	arr[0][0]=n;
	arr[0][1]=m;
	arr[0][2]=non;
	for(i=1;i<=non;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	cin>>str>>stc;
	p(arr,str,stc,d);
	x=1;
	while(x<=(m*n))
	{
		for(i=0;i<k;i++)
		{
			str++;
			x++;
			d=1;
			p(arr,str,stc,d);
		}
		for(i=0;i<k;i++)
		{
			stc++;
			x++;
			d=2;
			p(arr,str,stc,d);
		}
		k++;
		for(i=0;i<k;i++)
		{
			str--;
			x++;
			d=3;
			p(arr,str,stc,d);
		}
		for(i=0;i<k;i++)
		{
			stc--;
			x++;
			d=4;
			p(arr,str,stc,d);
		}
		k++;
	}
	return 0;
}
