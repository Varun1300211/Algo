#include <bits/stdc++.h>
using namespace std;
 
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
 
    cout <<"Following activities are selected "<< endl;
 
        i = 0;
    cout <<" "<< i;
 
        for (j = 1; j < n; j++)
    {
      if (s[j] >= f[i])
      {
          cout <<" " << j;
          i = j;
      }
    }	}
 
int main()
{
	int n;
	cout<<"Enter Size of Arrays: "<<endl;
	cin>>n;
	int s[n],f[n];
	cout<<"Enter Elements of Start: "<<endl;
    for(int i=0;i<n;i++){
    	cin>>s[i];
	}
	cout<<"Enter Elements of finish: "<<endl;
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	sort[f,f+n];
	printMaxActivities(S, F, n)
}
