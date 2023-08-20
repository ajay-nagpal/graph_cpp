

//prede dis by bfs


#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

#define initial 1
#define waiting 2
#define visited 3


#define NIL -1
#define infinite 9999

int distancee[MAX];
int predecessor[MAX];
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
        distancee[i]=infinite;
        predecessor[i]=NIL;
    }
}

void bfs(int v){
    queue<int>q;
    q.push(v);
    state[v]=waiting;
    distancee[v]=0;
    predecessor[v]=NIL;
    
    while(!q.empty()){
        v=q.front();
        q.pop();
        
        cout<<v<<" ";
        state[v]=visited;
        
        
        for(int i=0;i<n;i++){
            if(adj[v][i]&&state[i]==initial){
                q.push(i);
                state[i]=waiting;
                distancee[i]=distancee[v]+1;
                predecessor[i]=v;
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
    
    int desti;
    int path[MAX];
    int count;//to indexing path arr
    
    while(1){
        cout<<"enter destination vertex(-1 to quit)"<<endl;
        cin>>desti;
        
        if(desti<-1||desti>n-1){
            cout<<"destination vertex does not exist"<<endl;
            continue;
        }
        if(desti==-1)
            break;
            
        count=0;
         
        if(distancee[desti]==infinite){
            cout<<"no path exist"<<endl;
            continue;
        }
        else{
            cout<<"shortest distance bw these two vertices is "<<distancee[desti]<<endl;
            cout<<"path is "<<endl;
            
            int u;//to store predi of desti
            
            
            while(desti!=NIL){
                path[count++]=desti;
                desti=predecessor[desti];
                
                // path[count++]=desti;
                // u=predecessor[desti];
                // desti=u;
            }
            int i;
            // for( i=sizeof(path)/sizeof(path[0])-1;i>0;i--){
            //     cout<<path[i]<<"->";
            // }
            
            for( i=count-1;i>0;i--){
                cout<<path[i]<<"->";
            }
            cout<<path[i];
        }
        cout<<endl;
    }
}




