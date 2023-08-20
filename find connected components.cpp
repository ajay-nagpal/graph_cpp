



//find connected components

#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

#define initial 1
#define waiting 2
#define visited 3

int state[MAX];
int lable[MAX];

int adj[MAX][MAX];

int n;

void create_graph(){
    int u,edge,gt,origin,desti;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
    cout<<"enter grapg type 1 for directed 2 for undirected"<<endl;
    cin>>gt;
    if(gt==1)
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
            if(gt==2)
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
    }
}

void bfs(int v,int component){
    queue<int>q;
    q.push(v);
    state[v]=waiting;
    
    while(!q.empty()){
        v=q.front();
        q.pop();

        state[v]=visited;
        lable[v]=component;
        cout<<"vertex "<<v<<" component "<<component<<endl;
        
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
    
    int component=1;
    
    bfs(0,component);
    
    for(int i=0;i<n;i++){
        if(state[i]==initial){
            component++;
            bfs(i,component);
        }
    }
    
    cout<<"number of connected component "<<component<<endl;
    
    if(component==1)
        cout<<"graph is connected "<<endl;
    else
        cout<<"grapg is not connected "<<endl;
    
}



