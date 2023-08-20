
//spanning tree kruskal algo

#include<iostream>
#include<cstdlib>

#include<bits/stdc++.h>
using namespace std;

#define MAX 20
#define NIL -1


int n;

int father[MAX];

struct edge{
    int u,v;
    int wt_edge;
    //struct edge * link;
};

typedef pair<int,pair<int,int>> int1 ;//wt,u,v

priority_queue<int1,vector<int1>,greater<int1>>pq;

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
            pq.push({wt,{origin,desti}});
            //pq.push({wt,{desti,origin}});
        }
    }
}

void set_initial(){
    for(int i=0;i<n;i++){
        father[i]=NIL;
    }
}

void kruskal_maketree(struct edge tree[MAX]){
    int v1,v2,root1,root2;
    int count=0;// count of edges includede in tree
    
    while(!pq.empty()&&count<n){
        
         int1 p=pq.top();
         v1=p.second.first;
         v2=p.second.second;
         
         while(v1!=NIL){
             root1=v1;
             v1=father[v1];
         }
         while(v2!=NIL){
             root2=v2;
             v2=father[v2];
         }
         if(root1!=root2){
             tree[count].u=p.second.first;
             tree[count].v=p.second.second;
             tree[count].wt_edge=p.first;
             
             father[root2]=root1;
             count++;
         }
         pq.pop();
    }
    
    if(count<n-1){// kuki we use 0 as tree index
        cout<<"graph is not connected"<<endl;
        exit(1);
    }
}

int main(){
    create_graph();
    
    set_initial();
    
    struct edge tree[MAX];
    int wt_tree=0;
    
    kruskal_maketree(tree);
    
    cout<<"edges in tree are"<<endl;
    
    for(int i=0;i<n-1;i++){
        cout<<tree[i].u<<"->"<<tree[i].v<<endl;
        wt_tree+=tree[i].wt_edge;
    }
    cout<<"total wt of tree edges is "<<wt_tree<<endl;
}













