#include<iostream>
#include<cmath>
using namespace std;
/*int main(){
	float a,b,c,D,ans1,ans2;
	cout<<"Enter the quadratic equation numbers  : ";
	cin>>a>>b>>c;
	D=(b*b) - 4*a*c;
	ans1 = (-b + sqrt(D))/2*a;
	ans2 = (-b - sqrt(D))/2*a;
	cout<<"The roots are : "<<ans1<<" and "<<ans2; 
}
int main(){
	char x;
	cout<<"Enter a character : ";
	cin>>x;
	cout<<"ASCII value of "<<x<<" is "<<int(x);
}*/
#define V 100
#define INF 10000000
int dist[V+1][V+1];
void floydWarshall(int graph[][V+1])
{
    int i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    
    for (k = 0; k < V; k++) {
            
        for (i = 0; i < V; i++) {
                
            for (j = 0; j < V; j++) {
                
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
                // // Print the shortest distance matrix
                // printSolution(dist);
}

vector<int> CheapestRoundTripPro(int NumCities, vector<vector<int>> f) {
    int n = NumCities;
    int graph[V+1][V+1];
    vector<int> ans,k;
    for(int i=0;i<=V;i++){
        for(int j=0;j<=V;j++){
            graph[i][j] = INF;
        }
    }
    for(auto i : f){
        graph[i[0]][i[1]] = i[2];
    }
    floydWarshall(graph);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                k.push_back(dist[i][j] + dist[j][i]);
            }
        }
    }
    sort(k.begin(),k.end());
    if(k[0] >= INF) k[0] = INF;
    if(k[2] >= INF) k[2] = INF;
    ans.push_back(k[0]);
    ans.push_back(k[2]);
    return ans;
}
