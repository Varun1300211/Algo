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
vi ans;
bool vis[1000];
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
void dfs(vector<int>adj[],int node)
{
    vis[node]=true;

    for(auto it:adj[node])
    {
    	if(!vis[it])
    		dfs(adj,it);
    }

    ans.pb(node);
}
 int main(int argc, char const *argv[])
 {
    int n;
    cin>>n;
    vector<int>adj[n];
    loop(i,0,999)
    vis[i]=false;
    loop(i,0,n-1)
    {
    	int u,v;
    	cin>>u>>v;
    	adj[u].pb(v);
    }
     loop(i,0,n-1)
     {
     	if(!vis[i])
     		dfs(adj,i);
     }
     reverse(ans.begin(), ans.end());
     for(auto it: ans)
     cout<<it<<" ";
     cout<<endl; 
     return 0;
 }