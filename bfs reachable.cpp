








//bfs reachable

#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

#define initial 1
#define waiting 2
#define visited 3
int state[MAX];

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

void set_initial(){
    for(int i=0;i<n;i++){
        state[i]=initial;
    }
}

void bfs(int v){
    queue<int>q;
    q.push(v);
    state[v]=waiting;
    
    while(!q.empty()){
        v=q.front();
        q.pop();
        
        cout<<v<<" ";
        state[v]=visited;
        
        for(int i=0;i<n;i++){
            if(adj[v][i]&&state[i]==initial){
                q.push(i);
                state[i]=waiting;
            }
        }
    }
    cout<<endl;
}

int main() {
    create_graph();
    cout<<"adj is"<<endl;
    display(adj);
    
    set_initial();
    
    int v;
    cout<<"enter start vertex to traverse reachable vertex from it"<<endl;
    cin>>v;
    
    bfs(v);

    cout<<"to visit all vertices from any vertices  re-visit from initial state vertices"<<endl;
    for(int i=0;i<n;i++)
        if(state[i]==initial)
            bfs(i);
}









