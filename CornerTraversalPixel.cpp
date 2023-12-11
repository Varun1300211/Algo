#include<bits/stdc++.h>
using namespace std;
void edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);  
}
bool BFS(vector<int> adj[], int src, int dest, int v, int pred[])
{
    list<int> queue;
    bool visited[v];
    for (int i=0;i<v;i++) {
        visited[i]=false;
        pred[i]=-1;
}
    visited[src]=true;
    queue.push_back(src);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i=0;i<adj[u].size();i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);            
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
    return false;
}
void printShortestDistance(vector<int> adj[], int s,
                           int dest, int v)
{
    int pred[v];
     if (BFS(adj,s,dest,v,pred) == false) {
        cout <<"";   
    }
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    for (int i=path.size()-1; i>=0; i--)
        cout << path[i] << " ";
}
int main()
{
int source, dest;
int m,n,s;
cin>>m>>n>>s;
vector<int> adj[m*n+1];
int no,ne,e,se,so,sw,w,nw,j;
for(int i=1;i<=m*n;i++)
{
    cin>>j>>no>>ne>>e>>se>>so>>sw>>w>>nw;
   if(no==1)
    {
        edge(adj,j,j-n);        
    }
     if(ne==1)
    {
        edge(adj,j,j-n+1);
    }
     if(e==1)
    {
        edge(adj,j,j+1);
    }
    if(se==1)
    {
        edge(adj,j,j+n+1);
    }
    if(so==1)
    {
        edge(adj,j,j+n);
    }
    if(sw==1)
    {
        edge(adj,j,j+n-1);
    }
    if(w==1)
    {
        edge(adj,j,j-1);
    }
      if(nw==1)
    {
    edge(adj,j,j-n-1);
    }
}
printShortestDistance(adj, s, 1, m*n+1);
cout<<endl;
printShortestDistance(adj, s, n, m*n+1);
cout<<endl;
printShortestDistance(adj, s, m*n-n+1, m*n+1);
cout<<endl;
printShortestDistance(adj, s, m*n, m*n+1);
cout<<endl;
}
