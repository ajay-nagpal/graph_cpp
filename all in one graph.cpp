//adj matrix graph

#include<iostream>
using namespace std;

int adj[10][10];

int main(){
    int gt;
    cout<<"enter type of graph"<<endl;
    cout<<"enter 1 for undirected graph 2 for directed grph"<<endl;
    cin>>gt;

    int n;
    cout<<"enter number of vertices"<<endl;
    cin>>n;

    int maxedge;
    if(gt==1)
        maxedge=n*(n-1)/2;
    else
        maxedge=n*(n-1);

    int u,v;

    for(int i=0;i<maxedge;i++){
        cout<<"enter edge"<<endl;
        cin>>u;
        cin>>v;
        if(u==-1&&v==-1)
            break;
        if(u<0||u>=n||v<0||v>=n){
            cout<<"invalid index"<<endl;
            i--;
        }
        else{
            adj[u][v]=1;
            if(gt==1)
                adj[v][u]=1;
        }
    }
    cout<<"graph is"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}










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










//dfs graph

#include <iostream>
#include <stack>
using namespace std;

#define MAX 10

#define initial 1
#define visited 3

int state[MAX];

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

void dfs(int v){
    stack<int>s;
    s.push(v);
    
    while(!s.empty()){
        v=s.top();
        s.pop();
        
        if(state[v]==initial){
            state[v]=visited;
            cout<<v<<" ";
        }
            
        for(int i=n-1;i>0;i--){
            if(adj[v][i]&&state[i]==initial){
                s.push(i);
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
    cout<<"enter start vertex "<<endl;
    cin>>v;
    
    dfs(v);
}









//dfs recursion

#include <iostream>
using namespace std;

#define MAX 20

#define initial 1
#define visited 2 
#define finished 3 

int state[MAX];

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

int main() {
    create_graph();
    cout<<"adj is"<<endl;
    display(adj);
    
    set_initial();
    
    int v;
    cout<<"enter start vertex "<<endl;
    cin>>v;
    
    dfs(v);
}





//edge by dfs

#include <iostream>
using namespace std;

#define MAX 20

#define initial 1
#define visited 2 
#define finished 3 

int state[MAX];

int adj[MAX][MAX];

int n;
int timee=0;

int dis_time[MAX];
int fin_time[MAX];


void create_graph(){
    int u,edge,gt,origin,desti;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
    cout<<"enter grapg type 1 for directed "<<endl;
    cin>>gt;
   
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

void set_initial(){
    
    for(int i=0;i<n;i++){
        state[i]=initial;
    }
}

void dfs(int v){
    cout<<v<<endl;
    state[v]=visited;
    
    timee++;
    dis_time[v]=timee;
    
    for(int i=0;i<n;i++){
        if(adj[v][i]==1){
            if(state[i]==initial){
                cout<<"tree edge "<<v<<"->"<<i<<endl;
                dfs(i);
            }
            else if(state[i]==visited){
                cout<<"back edge "<<v<<"->"<<i<<endl;
            }
            else if(dis_time[v]<dis_time[i]){
                cout<<"forward edge "<<v<<"->"<<i<<endl;
            }
            else{
                cout<<"cross edge "<<v<<"->"<<i<<endl;
                cout<<"graph has cycle "<<endl;
            }
        }
    }
    state[v]=finished;
    
    timee++;
    fin_time[v]=timee;
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
    for(int i=0;i<n;i++){
        if(state[i]==initial)
            dfs(i);
    }
}


















//edge type undirected graph

#include <iostream>
using namespace std;

#define MAX 20
#define NIL -1

#define initial 1
#define visited 2 
#define finished 3 

int state[MAX];
int predecessor[MAX];
int adj[MAX][MAX];

int n;

void create_graph(){
    int u,edge,gt,origin,desti;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
    cout<<"enter grapg type 2 for undirected"<<endl;
    cin>>gt;
    
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
        predecessor[i]=NIL;
    }
}

void dfs(int v){
    cout<<v<<endl;
    state[v]=visited;
    
    for(int i=0;i<n;i++){
        // imp let 1->3 tree edge h then in undirected it will print 1->3 tree and 3->1 back
        // to stop printing 2 times for same edge we should add something in condition
        //predecessor[v]!=i
        if(adj[v][i]==1 && predecessor[v]!=i){
            if(state[i]==initial){
                cout<<"tree edge "<<v<<"->"<<i<<endl;
                predecessor[i]=v;
                dfs(i);
            }
            else if(state[i]==visited){
                cout<<"back edge "<<v<<"->"<<i<<endl;
                cout<<"graph has cycle "<<endl;
            }
        }
    }
    state[v]=finished;
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
    for(int i=0;i<n;i++){
        if(state[i]==initial)
            dfs(i);
    }
}










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








//graph connected or not check

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
    int connected=1;
    
    bfs(0);
    
    for(int i=0;i<n;i++){
        if(state[i]==initial){
            connected=0;
            break;
        }
    }
    if(connected)
        cout<<"graph is connected"<<endl;
    else
        cout<<"graph is not connected "<<endl;;

}















//intime fintime  dfs graph rec


#include <iostream>
using namespace std;

#define MAX 20

#define initial 1
#define visited 2 
#define finished 3 

int state[MAX];

int adj[MAX][MAX];

int n;
int timee=0;

int dis_time[MAX];
int fin_time[MAX];


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
    
    timee++;
    dis_time[v]=timee;
    
    for(int i=0;i<n;i++){
        if(adj[v][i]&&state[i]==initial){
            dfs(i);
        }
    }
    state[v]=finished;
    
    timee++;
    fin_time[v]=timee;
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
}
















//list adj graph


#include<iostream>
using namespace std;

struct edge;

struct vertex{
    int val;
    struct vertex * nextvertex;
    struct edge * firstedge;
}*start=NULL;

struct edge{
    struct edge * nextedge;
    struct vertex * destivertex;
};

void insertvertex(int u){
        struct vertex * temp=new (vertex);
        temp->val=u;
        temp->nextvertex=NULL;
        temp->firstedge=NULL;

        if(start==NULL){
            start=temp;
            return;
        }
        struct vertex* ptr=start;
        while(ptr->nextvertex!=NULL){
            ptr=ptr->nextvertex;
        }
        ptr->nextvertex=temp;
}
struct vertex * findvertex(int u){
    struct vertex  *ptr=start;
    while(ptr!=NULL){
        if(ptr->val==u)
            return ptr;
        ptr=ptr->nextvertex;
    }
    return NULL;
}

void insertedge(int origin,int desti){
    struct vertex *locateO=findvertex(origin);
    struct vertex *locateD=findvertex(desti);

    if(locateO==NULL){
        cout<<"start vertex not found"<<endl;
        return;
    }
    if(locateD==NULL){
        cout<<"end vertex not found"<<endl;
        return;
    }

    struct edge * temp=new  edge();
    temp->destivertex=locateD;
    temp->nextedge=NULL;

    if(locateO->firstedge==NULL){
        locateO->firstedge=temp;
        return;
    }
    struct edge * ptr=locateO->firstedge;
    while(ptr->nextedge!=NULL){
        ptr=ptr->nextedge;
    }
    ptr->nextedge=temp;
}

void deleteincomingedges(int u){
    struct vertex* ptr=start;

    while(ptr!=NULL){
        struct edge *temp;
        if(ptr->firstedge==NULL){
            ptr=ptr->nextvertex;
            continue;
        }
        if(ptr->firstedge->destivertex->val==u){
            temp=ptr->firstedge;
            ptr->firstedge=ptr->firstedge->nextedge;
            delete temp;
            continue;
        }
        struct edge * q;
        q=ptr->firstedge;
        while(q->nextedge!=NULL){
            if(q->nextedge->destivertex->val==u){
                temp=q->nextedge;
                q->nextedge=temp->nextedge;
                delete temp;
                continue;
            }
            q=q->nextedge;
        }
        ptr=ptr->nextvertex;
    }
}

void deletevertex(int u){
    deleteincomingedges(u);
    
    if(start==NULL){
        cout<<"no vertices to delete"<<endl;
        return;
    }
    struct vertex *temp,*q;
    if(start->val==u){
        temp=start;
        start=start->nextvertex;
    }
    else{
        q=start;
        while(q->nextvertex!=NULL){
            if(q->nextvertex->val==u)
                break;
            q=q->nextvertex;
        }
        if(q->nextvertex==NULL){
            cout<<"vertex not found"<<endl;
            return;
        }
        temp=q->nextvertex;
        q->nextvertex=temp->nextvertex;
    }
    struct edge *p=temp->firstedge,*tempE;
    while(p!=NULL){
        tempE=p;
        p=p->nextedge;
        delete tempE;
    }
    delete temp;
}

void deleteedge(int origin,int desti){
    struct vertex *locateO=findvertex(origin);

    if(locateO==NULL){
        cout<<"start vertex not found"<<endl;
        return;
    }
    if(locateO->firstedge==NULL){
        cout<<"edge not present"<<endl;
        return;
    }

    struct edge *temp;
    if(locateO->firstedge->destivertex->val==desti){
        temp=locateO->firstedge;
        locateO->firstedge=temp->nextedge;
        delete temp;
        return;
    }

    struct edge *q=locateO->firstedge;
    while(q->nextedge!=NULL){
        if(q->nextedge->destivertex->val==desti){
            temp=q->nextedge;
            q->nextedge=temp->nextedge;
            delete temp;
            return;
        }
        q=q->nextedge;
    }
    cout<<"edge not present "<<endl;
}

void display(){
    struct vertex * ptr;
    struct edge *q;

    ptr=start;
    while(ptr!=NULL){
        cout<<ptr->val<<"->";
        q=ptr->firstedge;
        while(q!=NULL){
            cout<<q->destivertex->val<<" , ";
            q=q->nextedge;
        }
        cout<<endl;
        ptr=ptr->nextvertex;
    }
}

int main(){
    int choice,u,origin,desti;
    while(1){
        cout<<"enter choice"<<endl;
        cout<<"1 for insert vertex"<<endl;
        cout<<"2 for insert edge"<<endl;
        cout<<"3 for delete vertex"<<endl;
        cout<<"4 for delete edge"<<endl;
        cout<<"5 for display"<<endl;
        cout<<"6 for exit"<<endl;
        
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"enter a vertex to insert"<<endl;
            cin>>u;
            insertvertex(u);
            break;

            case 2:
            cout<<"enter edge to insert"<<endl;
            cout<<"enter origin vertex"<<endl;
            cin>>origin;
            cout<<"enter destination vertex"<<endl;
            cin>>desti;

            insertedge(origin,desti);
            break;

            case 3:
            cout<<"enter vertex to delete"<<endl;
            cin>>u;
            deletevertex(u);
            break;

            case 4:
            cout<<"enter edge to delete"<<endl;
            cout<<"enter origin"<<endl;
            cin>>origin;
            cout<<"enter desti"<<endl;
            cin>>desti;
            
            deleteedge(origin,desti);
            break;

            case 5 :
            display();
            break;

            case 6:
            exit(1);

            default:
            cout<<"wrong choice enter"<<endl;
            break;
        }
    }
}








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






//path matrix 

#include <iostream>
using namespace std;

#define MAX 10
int n;
int adj[MAX][MAX],adjp[MAX][MAX];

void create_graph(int adj[MAX][MAX]){
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
        cout<<endl;
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


void mul(int m[MAX][MAX]){
    
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           m[i][j]=0;
           for(int k=0;k<n;k++){
               m[i][j]+=adjp[i][k]*adj[k][j];
           }
       }
    }
}
void power(int p){
    int temp[MAX][MAX];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adjp[i][j]=adj[i][j];
        }
    }
    
    for(int i=1;i<p;i++){
        mul(temp);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                adjp[j][k]=temp[j][k];
            }
        }
    }
}



int main(){
    int x[MAX][MAX],path[MAX][MAX];
    
    create_graph(adj);
    display(adj);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x[i][j]=0;
        }
    }
    
    for(int p=1;p<=n;p++){
        power(p);
        
        cout<<"adj matrix power " <<p <<" is"<<endl;
        display(adjp);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                x[i][j]+=adjp[i][j];
            }
        }
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
    
    cout<<"path matrix is "<<endl;
    display(path);
}










//prede tree graph all verti visit


#include <iostream>
#include <stack>
using namespace std;

#define MAX 10

#define initial 1
#define visited 3

#define NIL -1

int state[MAX];
int predecessor[MAX];
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
        predecessor[i]=NIL;
    }
}

void dfs(int v){
    stack<int>s;
    s.push(v);
    
    while(!s.empty()){
        v=s.top();
        s.pop();
        
        if(state[v]==initial){
            state[v]=visited;
            cout<<v<<" ";
        }
            
        for(int i=n-1;i>=0;i--){
            if(adj[v][i]&&state[i]==initial){
                s.push(i);
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
    cout<<"enter start vertex "<<endl;
    cin>>v;
    
    dfs(v);
    for(int i=0;i<n;i++){
        if(state[i]==initial){
            dfs(i);
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<"vertex "<<i<<"  predecessor "<<predecessor[i]<<endl;
    }
    
    cout<<"Tree Edges "<<endl;
    
    for(int i=0;i<n;i++){
        if(predecessor[i]!=-1){
            cout<<predecessor[i]<<"->"<<i<<endl;
        }
    }
}




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








//shortest dis floydwarshall all pair algo


#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 20

#define infinite 9999
#define NIL -1;

int adj[MAX][MAX];
int D[MAX][MAX];
int prede[MAX][MAX];

int n;


void display(int adj[MAX][MAX]){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

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

void set(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==0){
                D[i][j]=infinite;
                prede[i][j]=NIL;
            }
            else{
                D[i][j]=adj[i][j];
                prede[i][j]=i;
            }
        }
    }
}

void floyd_warshall(){
    int count=0;
    
    // to calc D0 to Dn-1 cz vertex start from D0
    for(int k=0;k<n;k++){//D0 to Dn-1
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    
                    D[i][j]=D[i][k]+D[k][j];
                    prede[i][j]=prede[k][j];
                }
            }
        }
        cout<<endl;
        cout<<"D,"<<count++<<"is "<<endl;
        display(D);
    }
    
    for(int i=0;i<n;i++){
        if(D[i][i]<0){
            cout<<"error: graph contains negative cycle"<<endl;
            exit(1);
        }
    }
}

void find_path(int v,int d){
    int path[MAX];
    int count=0;//for indexing path[]
    
    if(D[v][d]==infinite){
        cout<<"no path exist"<<endl;
        return;
    }
    while(d!=v){
        path[count++]=d;
        d=prede[v][d];
    }
    path[count]=v;
    
    int i;
    for(i=count;i>=1;i--){
        cout<<path[i]<<"->";
    }
    cout<<path[i]<<endl;
}

int main(){
    create_graph();
    
    cout<<"adj matrix is"<<endl;
    display(adj);
    
    set();
    cout<<"after set"<<endl;
    
    cout<<"D,-1 is"<<endl;
    display(D);
    
    cout<<"prede,-1 is"<<endl;
    display(prede);
    
    floyd_warshall();
    
    cout<<"shortest path matrix is D "<<n-1<<endl;
    display(D);
    
    int v,d;
    while(1){
        cout<<"enter source vertex(enter -1 to break)"<<endl;
        cin>>v;
        
        if(v==-1)
            break;
        cout<<"enter destination vertex"<<endl;
        cin>>d;
        
        if(v<0||d<0||v>=n||d>=n){
            cout<<"enter valid vertex"<<endl;
            continue;
        }
        
        cout<<"shortest path is"<<endl;
        find_path(v,d);
        cout<<"path lennght is "<<D[v][d]<<endl;
    }
}








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






//warshall path matrix

#include <iostream>
using namespace std;

#define MAX 10
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


int main() {
    create_graph();
    cout<<"adj is"<<endl;
    display(adj);
    
    int p[MAX][MAX];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            p[i][j]=adj[i][j];
        }
    }
    cout<<"p-1"<<" is "<<endl;
    display(p);
    int k=0;
    for(k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p[i][j]=p[i][j]||(p[i][k]&&p[k][j]);
            }
        }
        cout<<"p"<<k<<" is "<<endl;
        display(p);
    }
    
    cout<<"p"<<k-1<<" is path matrix"<<endl;
}














