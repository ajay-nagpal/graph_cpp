



//edge type undirected graph

#include <iostream>
using namespace std;

#define MAX 20
#define NIL -1

#define initial 1
#define visited 2 
#define finished 3 

int state[MAX];
int predecessor[MAX];
int adj[MAX][MAX];

int n;

void create_graph(){
    int u,edge,gt,origin,desti;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
    cout<<"enter grapg type 2 for undirected"<<endl;
    cin>>gt;
    
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
            adj[desti][origin]=1;
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

void set_initial(){
    
    for(int i=0;i<n;i++){
        state[i]=initial;
        predecessor[i]=NIL;
    }
}

void dfs(int v){
    cout<<v<<endl;
    state[v]=visited;
    
    for(int i=0;i<n;i++){
        // imp let 1->3 tree edge h then in undirected it will print 1->3 tree and 3->1 back
        // to stop printing 2 times for same edge we should add something in condition
        //predecessor[v]!=i
        if(adj[v][i]==1 && predecessor[v]!=i){
            if(state[i]==initial){
                cout<<"tree edge "<<v<<"->"<<i<<endl;
                predecessor[i]=v;
                dfs(i);
            }
            else if(state[i]==visited){
                cout<<"back edge "<<v<<"->"<<i<<endl;
                cout<<"graph has cycle "<<endl;
            }
        }
    }
    state[v]=finished;
}

int main() {
    create_graph();
    cout<<"adj is"<<endl;
    display(adj);
    
    set_initial();
    
    int v;
    cout<<"enter start vertex "<<endl;
    cin>>v;
    
    dfs(v);
    for(int i=0;i<n;i++){
        if(state[i]==initial)
            dfs(i);
    }
}






