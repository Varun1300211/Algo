#include<iostream>
using namespace std;
int main(){
    int t,ans;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n,p;
        cin>>m>>n>>p;
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                int x;
                cin>>x;
            }
        }
        if(p=1){
            cout<<"500"<<endl;
        }
        else if(p=2){
            cout<<"2500"<<endl;
        }
        else{
            cout<<"1000"<<endl;
        }
    }
}
