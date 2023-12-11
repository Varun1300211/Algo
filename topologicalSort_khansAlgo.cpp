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


 int main(int argc, char const *argv[])
 {
    int n;
    cin>>n;
    vector<int>adj[n];
    vector<int>indegree(n+1);
    loop(i,0,n-1)
    {
    	int u,v;
    	cin>>u>>v;
    	indegree[v]++;
    	adj[u].pb(v);
    }
    queue<int>q;
    vi ans;
    ll visited_nodes=0;
    loop(i,0,n-1)
    {
    	if(indegree[i]==0)
    		q.push(i);
    } 
    while(!q.empty())
    {
    	visited_nodes++;
       int node = q.front();
       q.pop();

       for(auto it:adj[node])
       {
       	  indegree[it]--;
       	  if(indegree[it]==0)q.push(it);
       }
       ans.pb(node);
    }
    if(visited_nodes!=n)
    {
    	cout<<"Graph has a Cycle"<<endl;
    }
    else
    {
    	for(auto it:ans)
    		cout<<it<<" ";
    	cout<<endl;
    }
 }