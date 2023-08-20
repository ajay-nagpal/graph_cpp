//adj matrix graph

#include<iostream>
using namespace std;

int adj[10][10];

int main(){
    int gt;
    cout<<"enter type of graph"<<endl;
    cout<<"enter 1 for undirected graph 2 for directed grph"<<endl;
    cin>>gt;

    int n;
    cout<<"enter number of vertices"<<endl;
    cin>>n;

    int maxedge;
    if(gt==1)
        maxedge=n*(n-1)/2;
    else
        maxedge=n*(n-1);

    int u,v;

    for(int i=0;i<maxedge;i++){
        cout<<"enter edge"<<endl;
        cin>>u;
        cin>>v;
        if(u==-1&&v==-1)
            break;
        if(u<0||u>=n||v<0||v>=n){
            cout<<"invalid index"<<endl;
            i--;
        }
        else{
            adj[u][v]=1;
            if(gt==1)
                adj[v][u]=1;
        }
    }
    cout<<"graph is"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}










