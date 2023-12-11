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
struct knapsack
{
	double p_w;
	double weight,profit,x;
};
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
bool cmp(knapsack a,knapsack b)
{
   return (a.p_w > b.p_w);
}

 int main(int argc, char const *argv[])
 { 
 	 double w;int n;
     cout<<"Enter number of Items:";
     cin>>n;
     knapsack arr[n+1];
     cout<<"Enter the profit and weight of the Item:"<<endl;
     arr[0].p_w=0;arr[0].weight=0;arr[0].profit=0;arr[0].x=0;
     loop(i,1,n)
     {
     	cin>>arr[i].profit>>arr[i].weight;
     	arr[i].p_w = ((arr[i].profit))/(arr[i].weight);
     }   
   
     cout<<endl; 
     cout<<"Enter the knapsack capacity:";
     cin>>w;
     sort(arr+1,arr+n+1,cmp);
     int i=1;
     double mx_profit=0;
     while(w>0 && i<=n)
     {
       arr[i].x = min(w,arr[i].weight);
       w = w-arr[i].x;
       arr[i].x = ((arr[i].x)*1.0)/arr[i].weight;
      // cout<<"w:"<<w<<" arr[i].x :"<<arr[i].x<<endl;
       mx_profit+= (arr[i].x*arr[i].profit); 
       i++;
     }

     cout<<endl;
     cout<<"Maximum Profit is:"<<mx_profit;
     return 0;
 }
