



//shortest dis floydwarshall all pair algo


#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 20

#define infinite 9999
#define NIL -1;

int adj[MAX][MAX];
int D[MAX][MAX];
int prede[MAX][MAX];

int n;


void display(int adj[MAX][MAX]){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void create_graph(){
    int u,edge,gt,origin,desti;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
    
    edge=n*(n-1);

    for(int i=0;i<edge;i++){
        cout<<"enter edge"<<endl;
        cin>>origin;
        cin>>desti;
        
        if(origin==-1&&desti==-1)
            break;
        
        int wt;
        cout<<"enter weight on edge"<<endl;
        cin>>wt;
        
        if(origin<0||desti<0||origin>=n||desti>=n){
            cout<<"invalid edge"<<endl;
            i--;
        }
        else{
            adj[origin][desti]=wt;
        }
    }
}

void set(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==0){
                D[i][j]=infinite;
                prede[i][j]=NIL;
            }
            else{
                D[i][j]=adj[i][j];
                prede[i][j]=i;
            }
        }
    }
}

void floyd_warshall(){
    int count=0;
    
    // to calc D0 to Dn-1 cz vertex start from D0
    for(int k=0;k<n;k++){//D0 to Dn-1
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    
                    D[i][j]=D[i][k]+D[k][j];
                    prede[i][j]=prede[k][j];
                }
            }
        }
        cout<<endl;
        cout<<"D,"<<count++<<"is "<<endl;
        display(D);
    }
    
    for(int i=0;i<n;i++){
        if(D[i][i]<0){
            cout<<"error: graph contains negative cycle"<<endl;
            exit(1);
        }
    }
}

void find_path(int v,int d){
    int path[MAX];
    int count=0;//for indexing path[]
    
    if(D[v][d]==infinite){
        cout<<"no path exist"<<endl;
        return;
    }
    while(d!=v){
        path[count++]=d;
        d=prede[v][d];
    }
    path[count]=v;
    
    int i;
    for(i=count;i>=1;i--){
        cout<<path[i]<<"->";
    }
    cout<<path[i]<<endl;
}

int main(){
    create_graph();
    
    cout<<"adj matrix is"<<endl;
    display(adj);
    
    set();
    cout<<"after set"<<endl;
    
    cout<<"D,-1 is"<<endl;
    display(D);
    
    cout<<"prede,-1 is"<<endl;
    display(prede);
    
    floyd_warshall();
    
    cout<<"shortest path matrix is D "<<n-1<<endl;
    display(D);
    
    int v,d;
    while(1){
        cout<<"enter source vertex(enter -1 to break)"<<endl;
        cin>>v;
        
        if(v==-1)
            break;
        cout<<"enter destination vertex"<<endl;
        cin>>d;
        
        if(v<0||d<0||v>=n||d>=n){
            cout<<"enter valid vertex"<<endl;
            continue;
        }
        
        cout<<"shortest path is"<<endl;
        find_path(v,d);
        cout<<"path lennght is "<<D[v][d]<<endl;
    }
}







