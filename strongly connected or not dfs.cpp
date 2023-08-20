


//strongly connected or not dfs




#include <iostream>
using namespace std;

#define MAX 20

#define initial 1
#define visited 2 
#define finished 3 

int state[MAX];

int adj[MAX][MAX];
int adjt[MAX][MAX];//for rev

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

void dfs(int v){
    cout<<v<<" ";
    state[v]=visited;
  
    for(int i=0;i<n;i++){
        if(adj[v][i]&&state[i]==initial){
            dfs(i);
        }
    }
    state[v]=finished;
}


void dfst(int v){
    cout<<v<<" ";
    state[v]=visited;
  
    for(int i=0;i<n;i++){
        if(adjt[v][i]&&state[i]==initial){
            dfst(i);
        }
    }
    state[v]=finished;
}

void rev_graph(){
   for(int i=0;i<n;i++){
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(adj[i][j]==1){
                   adjt[j][i]=1;
               }
           }
       }
   }
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
    int b=true;
    for(int i=0;i<n;i++){
        if(state[i]==initial){
            cout<<"graph is not strongly connected"<<endl;
            b=false;
            break;
        }
    }
    
    if(b){
        cout<<endl;
        cout<<"all vertices are reachable from v"<<endl;
        cout<<"now reverse the graph and perform dfs"<<endl;
        
        rev_graph();
        display(adjt);
        
        set_initial(); 
        dfst(v);
        
        int B=true;
        for(int i=0;i<n;i++){
            if(state[i]==initial){
                cout<<endl;
                cout<<"graph is not strongly connected"<<endl;
                B=false;
                break;
            }
        }
        
        if(B){
            cout<<endl;
            cout<<"graph is strongly connected"<<endl;
        }
    }
}










