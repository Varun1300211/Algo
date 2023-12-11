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
ll parent[1000];
void file_i_o()
{
    ios::sync_with_stdio(false), 
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
}
/*
void sort_(int prof[],int deadline[],char job[],int n)
{
   for(int i=0;i<n;i++)
   {
   	 for(int j=i+1;j<n;j++)
   	 if(prof[i]<prof[j])
   	 {
   	 	swap(prof[i],prof[j]);
   	 	swap(deadline[i],deadline[j]);
   	 	swap(job[i],job[j]);
   	 }
   }
}
void solve()
{
	cout<<"0"<<endl;
	for(int i=0;i<1000;i++)
		parent[i]=i;
   int n;
   cout<<"Enter the number of Jobs:";
   cin>>n;
   int prof[n],deadline[n];
   char job[n];
   cout<<"Enter the Job and their Profit and Deadline:"<<endl;
   loop(i,0,n-1)
   {
   	 cin>>job[i]>>prof[i]>>deadline[i];
   }
   cout<<"1"<<endl;
   sort_(prof,deadline,job,n);
   cout<<"2"<<endl;
   char jobSeq[n+1];
   loop(i,0,n)
   jobSeq[i]='*';
   for(int i=0;i<n;i++)
   {
     int slot = get(deadline[i]);
     if(slot>0)
     {
     	jobSeq[slot]=job[i];
     	cout<<job[i]<<endl;
     	union_(slot-1,slot);   
     } 
   }   
  cout<<"3"<<endl;
  loop(i,0,n-1)
  cout<<jobSeq[i]<<endl;
   
}
 int main(int argc, char const *argv[])
 {
     //file_i_o();
     //ll t;
     //t=1;
     //cin>>t;
   //  while(t--)
     solve();

     
     return 0;
 }
*/
//----------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

struct Job
{
	char name;
	int profit,deadline;
};

void union_(int a,int b)
{
   parent[b]=a;
}

int get(int a)
{
	return (a==parent[a]?a:parent[a]=get(parent[a]));
}

bool cmp(Job a,Job b)
{
	if(a.profit==b.profit)
		return a.deadline>b.deadline;
	return a.profit>b.profit;
}
int main()
{
	
	for(int i=0;i<1000;i++)
		parent[i]=i;
 
   int n;
   cout<<"Enter the number of Jobs:";
   cin>>n;
   Job arr[n+1];
     arr[0].name='*';arr[0].profit=0;arr[0].deadline=0;
   cout<<"Enter the Job name,Profit and Deadline:"<<endl;
   loop(i,1,n)
   {
   	 cin>>arr[i].name>>arr[i].profit>>arr[i].deadline;
   }

   sort(arr,arr+n,cmp);

   ll mx_profit=0;
   cout<<endl;
   cout<<"Job Sequence:";
   for(int i=1;i<=n;i++)
   {
   	 int slot = get(arr[i].deadline);
      //cout<<slot<<" ";
   	 if(slot>0)
   	 {
   	 	union_(get(slot-1),slot);
   	 	cout<<arr[i].name<<" ";
   	 	mx_profit+=arr[i].profit;
   	 }
   }
   cout<<endl;
   cout<<"Max Profit:"<<mx_profit<<endl;
}



























