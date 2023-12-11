#include<bits/stdc++.h>
using namespace std;

bool check(int st ,queue<int> z){
	
	queue<int> q = z;
	int val = q.front(); bool t=0;
	while(!q.empty()){
		
		if(!(st>q.front() && val<=q.front()))
		{
			t=1;
			break;
		}
		q.pop();
		
	}
	return t;
}

void printQ(queue<int> z){
	
	queue<int> q = z;
	while(!q.empty()){
		
		cout<< q.front() << " ";
		q.pop();
	}
	cout<<"\n";
}

void printS(stack<int> z){
	
	stack<int> q = z;
	while(!q.empty()){
		
		cout<< q.top() << " ";
		q.pop();
	}
	cout<<"\n";
}

int main(){
	
	queue<int> Q;
	stack<int> S;
	
	int N;
	cin>>N;
	while(N!=0){
		
		int x;
		cin>>x;
		
		if(Q.empty() && S.empty())
		Q.push(x);
		else{
			if(x>=Q.back())
			Q.push(x);
			else if(S.empty() || x<=S.top())
			S.push(x);
			else{
				while(!S.empty()){
					
					int v = S.top();
					
					if(v < Q.front())
					{
						Q.push(v);
						S.pop();
					}
					else if(check(v,Q)==0){
						
						Q.push(v);
						S.pop();
					}
					else if(v == Q.back()){
						
						Q.push(v);
						S.pop();
					}
					else
					{
						Q.push(Q.front());
						Q.pop();
					}	
				}
				
				while(Q.front()<x){
					
					Q.push(Q.front());
					Q.pop();
				}
				
				S.push(Q.front());
				Q.pop();
				
				S.push(x);
				
				while(Q.front()>=Q.back()){
					
					Q.push(Q.front());
					Q.pop();
				}
			}
		}
		
		if(!Q.empty())
		printQ(Q);
		
		if(!S.empty())
		printS(S);
		
		N--;
	}
}
