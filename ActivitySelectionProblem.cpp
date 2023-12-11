#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define ii insert
#define vi vector<long long int>
const int N=1e5+5;
const int mod=1e9+7;
const ll int_max=1e18;
#define loop(i,j,k) for(ll i=j;i<=k;i++)
#define looprev(i,j,k) for(ll i=j;i>=k;i--)
using namespace std;


struct times
{
	int start,finish;
};

int main(int argc, char const *argv[])
 {
     int n;
     cout<<"Enter the number of activities:";
     cin>>n;
     times arr[n];
     cout<<"Enter the start and finish time of the acticity: "<<endl;
     loop(i,0,n-1)
     {
     	cin>>arr[i].start>>arr[i].finish;
     }

     vector<int>ans;
     ans.pb(1);
     int k=0;
     loop(i,1,n-1)
     {
     	if(arr[i].start>=arr[k].finish)
     	{
     		ans.pb(i+1);
     		k=i;
     	}
     }

     cout<<"Activities will be selected in this order:";
     for(auto it:ans)
     	cout<<it<<" ";
     cout<<endl;

    return 0;
 }