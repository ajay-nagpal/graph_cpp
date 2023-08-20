




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






