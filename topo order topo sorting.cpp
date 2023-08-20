
//topological order topo sorting

#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

#define MAX 20
#define NIL -1

int n;

int adj[MAX][MAX];

queue<int>q;


void create_graph(){
    int u,edge,origin,desti;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
  
    edge=n*(n-1);
 
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

int find_inde(int v){
    int indeg=0;
    for(int i=0;i<n;i++){
        if(adj[i][v]==1){
            indeg++;
        }
    }
    return indeg;
}

int main(){
    create_graph();
    display(adj);
    
    int count=0;
    int topo[MAX],inde[MAX];
    
    for(int i=0;i<n;i++){
        inde[i]=find_inde(i);
        
        if(inde[i]==0){
            q.push(i);
        }
    }
    
    int v;
    while(!q.empty() && count<n){
        v=q.front();
        q.pop();
        
        topo[count++]=v;
        
        // delete outgoing from v update inde[i] and if 0 then insert
        for(int i=0;i<n;i++){
            if(adj[v][i]==1){
                adj[v][i]=0;
                inde[i]=inde[i]-1;
                
                if(inde[i]==0){
                    q.push(i);
                }
            }
        }
    }
    
    if(count<n){
        cout<<"queue get empty in b/w procesure "<<endl;
        cout<<"this implies that there is a cycle present"<<endl;
        cout<<"no topo order possivble"<<endl;
        
        exit(1);
    }
    
    cout<<"topo order is "<<endl;
    for(int i=0;i<count;i++){
        cout<<topo[i]<<" ";
    }
}
