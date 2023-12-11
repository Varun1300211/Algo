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
bool vis[1000];
void dfs(vector<int>adj[],int node)
{
	vis[node]=true;

	for(auto it:adj[node])
	{
		if(!vis[it])
		 dfs(adj,it);
	}
}

bool is_connected(vector<int> adj[],int n)
{
     for(int i=0;i<n;i++)
     	vis[i]=false;

     dfs(adj,0);

     for(int i=0;i<n;i++)
     {
     	if(!vis[i])
     		return false;
     }
     return true;
}
 int main(int argc, char const *argv[])
 {
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];
    int degree[n]={0};
    loop(i,0,e-1)
    {
       int u,v;
       cin>>u>>v;
       adj[u].pb(v);
       adj[v].pb(u);
       degree[u]++;
       degree[v]++;
    } 
    
    if(!is_connected(adj,n))
    {
    	cout<<"Graph has neither Eulerian Path nor Eulerian circuit"<<endl;
    	return 0;
    }


    int odd=0,even=0;
    loop(i,0,n-1)
    {
      if(degree[i]&1)
      {
      	odd++;
      }
      else
      {
      	even++;
      }
    } 

    if(odd==0)
    {
    	cout<<"Graph is Eulerian"<<endl;
    }
    else if(odd==2)
    {
    	cout<<"Graph has Eulerian Path"<<endl;
    }
    else
    {
    	cout<<"Graph has neither Eulerian Path nor Eulerian circuit"<<endl;
    }

     return 0;
 }