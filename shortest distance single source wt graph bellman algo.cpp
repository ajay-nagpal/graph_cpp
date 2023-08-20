
//shortest distance single source wt graph bellman algo



#include <iostream>
#include<queue>
#include<cstdlib>
using namespace std;

#define MAX 20

#define infinite 9999
#define NIL -1

int adj[MAX][MAX];

int pathlenght[MAX];
int prede[MAX];

int count_ins=0;// to count how many time a vertex get inserted in queue to check negative cycle

int is_present[MAX];
queue<int>q;

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

int bellman(int v){
    pathlenght[v]=0;
    int curr;
    
    while(!q.empty()){
        curr=q.front();
        if(curr==v){
            count_ins++;
        }
        if(count_ins>n)
            return 0;
        
        q.pop();
        is_present[curr]=false;
        
        //check adj of curr which are temp
        
        for(int i=0;i<n;i++){
            if(adj[curr][i]!=0){
                // do relabeling if required
                if(pathlenght[curr]+adj[curr][i]<pathlenght[i]){
                    
                    pathlenght[i]=pathlenght[curr]+adj[curr][i];
                    prede[i]=curr;
                    
                    if(!is_present[i]){
                        q.push(i);
                        is_present[i]=true;
                    }
                }
            }
        }
    }
    return 1;
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
        prede[i]=NIL;
        pathlenght[i]=infinite;
        is_present[i]=false;
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
    
    q.push(v);
    is_present[v]=true;
    
    int b=bellman(v);
    if(!b){
        cout<<"error: grapg contains negative cycle "<<endl;
        exit(1);
    }
    
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


