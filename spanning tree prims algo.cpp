





//spanning tree prims algo


#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX 20
#define temp 1 
#define perma 2 

#define infinite 9999
#define NIL -1

int n;

int adj[MAX][MAX];
int prede[MAX];
int state[MAX];
int length[MAX];

struct edge{
    int u,v;
};

void create_graph(){
    int u,edge,et,origin,desti;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
    
    edge=n*(n-1)/2;

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
            adj[desti][origin]=wt;
        }
    }
}

void set_initial(){
    for(int i=0;i<n;i++){
        state[i]=temp;
        prede[i]=NIL;
        length[i]=infinite;
    }
}

int min_temp(){
    int k=NIL,min=infinite;
    
    for(int i=0;i<n;i++){
        if(state[i]==temp && length[i]<min){
            min=length[i];
            k=i;
        }
    }
    return k;
}
void prim_maketree(int root,struct edge tree[MAX]){
    
    int curr;
    int count=0;// to count total edges cz  edges==n-1 then tree complete if > then not connected graph
    length[root]=0;
    while(1){
        curr=min_temp();
        if(curr==NIL){
            if(count==n-1){
                return;
            }
            else{
                cout<<"graph is not connected no spanning tree is possible"<<endl;
                exit(1);
            }
        }
        
        state[curr]=perma;
        if(curr!=root){
            tree[count].u=prede[curr];
            tree[count].v=curr;
            count++;
        }
        
        for(int i=0;i<n;i++){
            if(adj[curr][i]>0&& state[i]==temp){
                if(adj[curr][i]<length[i]){
                    prede[i]=curr;
                    length[i]=adj[curr][i];
                }
            }
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

int main(){
    create_graph();
    display(adj);
    
    set_initial();
    
    int wt_tree=0;// to store wt of finat wt_tree
    int root;
    
    cout<<"enter root vertex for tree"<<endl;
    cin>>root;
    
    struct edge tree[MAX];// 1 edge struct edge type ki u se v but kai sari hogi
                            // to store edges tree[0].u,tree[0].v// source desti vertex
    
    prim_maketree(root,tree);
    
    cout<<"edges in tree are"<<endl;
    
    for(int i=0;i<n-1;i++){
        cout<<tree[i].u<<"->"<<tree[i].v<<endl;
        wt_tree+=adj[tree[i].u][tree[i].v];
    }
    cout<<"total wt of tree edges is "<<wt_tree<<endl;
}






