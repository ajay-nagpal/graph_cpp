

//shortest distance wt graph dijkstra algo


#include <iostream>
using namespace std;

#define MAX 20

#define infinite 9999
#define NIL -1
#define  temp 0 
#define perma 1 

int state[MAX];
int adj[MAX][MAX];

int pathlenght[MAX];
int prede[MAX];

int n;

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

int find_min_temp(){
    int k=NIL,min=infinite;
    
    for(int i=0;i<n;i++){
        if(state[i]==temp && pathlenght[i]<min){
            min=pathlenght[i];
            k=i;
        }
    }
    return k;
}

void dijkstra(int v){
    pathlenght[v]=0;
    int curr;
    
    while(1){
        curr=find_min_temp();
        if(curr==NIL)
            return;
        state[curr]=perma;
        
        //check adj of curr which are temp
        
        for(int i=0;i<n;i++){
            if(adj[curr][i]!=0 && state[i]==temp){
                // do relabeling if required
                if(pathlenght[curr]+adj[curr][i]<pathlenght[i]){
                    
                    pathlenght[i]=pathlenght[curr]+adj[curr][i];
                    prede[i]=curr;
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

void set_initial(){
    
    for(int i=0;i<n;i++){
        state[i]=temp;
        prede[i]=NIL;
        pathlenght[i]=infinite;
    }
}

void find_path(int v,int d){
    
    int path[MAX];//to store path
    int count=0;//to count number of vertices in the shortest path
    int length=0;//to store the path length
    
    int predecessor;// to store prede of d in each step to ad pathlenght
    
    while(d!=v){
        path[count++]=d;
        predecessor=prede[d];
        
        length+=adj[predecessor][d];
        d=predecessor;
    }
    path[count]=v;
    
    cout<<"shortest path is"<<endl;
    
    int i;
    for(i=count;i>=1;i--){
        cout<<path[i]<<"->";
    }
    cout<<path[i]<<endl;
    
    cout<<"shortest distance is "<<length<<endl;
}

int main() {
    create_graph();
    cout<<"adj is"<<endl;
    display(adj);
    
    set_initial();
    
    int v;
    cout<<"enter source vertex "<<endl;
    cin>>v;
    
    dijkstra(v);
    
    int d;
    while(1){
        cout<<"enter destination vertex(-1 to quit)"<<endl;
        cin>>d;
        
        if(d==-1)
            break;
        if(d<0||d>=n)
            cout<<"vertex doesn't exist"<<endl;
        else if (d==v)
            cout<<"source and destination vertex are same"<<endl;
        else if(pathlenght[d]==infinite)
            cout<<"there is no path from source to destination"<<endl;
        else
            find_path(v,d); 
     }
}



