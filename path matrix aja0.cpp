

//path matrix aj

#include <iostream>
using namespace std;

// int n=4;//number of vertices
// int adj[n][n];

#define MAX 100
int adj[MAX][MAX],adjp[MAX][MAX],path[MAX][MAX],x[MAX][MAX];


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


void mul(int temp[MAX][MAX]){
    
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           temp[i][j]=0;
           for(int k=0;k<n;k++){
               temp[i][j]+=adjp[i][k]*adj[k][j];
           }
       }
    }
}

void power(int p){
   if(p==1){
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               adjp[i][j]=adj[i][j];
           }
       }
   }
   else{
       int temp[MAX][MAX];
       mul(temp);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                adjp[j][k]=temp[j][k];
            }
        }
   }
   
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x[i][j]+=adjp[i][j];
        }
    }
}


int main() {
    create_graph();
    display(adj);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x[i][j]=0;
        }
    }
    
    for(int p=1;p<=n;p++){
        power(p);
    }
    cout<<"matrix xafter su of all power till n "<<endl;
    display(x);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i][j])
                path[i][j]=1;
            else
                path[i][j]=0;
        }
    }
    cout<<"matrix p "<<endl;
    display(path);
}





