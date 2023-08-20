





//warshall path matrix

#include <iostream>
using namespace std;

#define MAX 10
int adj[MAX][MAX];

int n;

void create_graph(){
    int u,edge,et,origin,desti;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
    cout<<"enter edge type 1 for directed 2 for undirected"<<endl;
    cin>>et;
    if(et==1)
        edge=n*(n-1);
    else
        edge=n*(n-1)/2;
        
    for(int i=0;i<edge;i++){
        cout<<"enter edge"<<endl;
        cin>>origin;
        cin>>desti;
        if(origin==-1&&desti==-1)
            break;
        if(origin<0||desti<0||origin>=n||desti>=n){
            cout<<"invalid edge"<<endl;
            i--;
        }
        else{
            adj[origin][desti]=1;
        }
    }
}

void display(int adj[MAX][MAX]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main() {
    create_graph();
    cout<<"adj is"<<endl;
    display(adj);
    
    int p[MAX][MAX];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            p[i][j]=adj[i][j];
        }
    }
    cout<<"p-1"<<" is "<<endl;
    display(p);
    int k=0;
    for(k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p[i][j]=p[i][j]||(p[i][k]&&p[k][j]);
            }
        }
        cout<<"p"<<k<<" is "<<endl;
        display(p);
    }
    
    cout<<"p"<<k-1<<" is path matrix"<<endl;
}

