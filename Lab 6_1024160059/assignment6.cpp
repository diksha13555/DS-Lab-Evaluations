#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* headDLL=NULL;
Node* tailDLL=NULL;

void insertDLL(int x,int pos){
    Node* n=new Node{x,NULL,NULL};
    if(!headDLL){
        headDLL=tailDLL=n;
    }else if(pos==1){
        n->next=headDLL;
        headDLL->prev=n;
        headDLL=n;
    }else if(pos==2){
        n->prev=tailDLL;
        tailDLL->next=n;
        tailDLL=n;
    }
}

void insertAfterDLL(int key,int x){
    Node* t=headDLL;
    while(t&&t->data!=key) t=t->next;
    if(!t) return;
    Node* n=new Node{x,t->next,t};
    if(t->next) t->next->prev=n;
    t->next=n;
    if(t==tailDLL) tailDLL=n;
}

void insertBeforeDLL(int key,int x){
    if(headDLL->data==key){
        insertDLL(x,1);
        return;
    }
    Node* t=headDLL;
    while(t&&t->data!=key) t=t->next;
    if(!t) return;
    Node* n=new Node{x,t,t->prev};
    t->prev->next=n;
    t->prev=n;
}

void deleteDLL(int key){
    Node* t=headDLL;
    while(t&&t->data!=key) t=t->next;
    if(!t) return;
    if(t==headDLL){
        headDLL=headDLL->next;
        if(headDLL) headDLL->prev=NULL;
    }else if(t==tailDLL){
        tailDLL=tailDLL->prev;
        tailDLL->next=NULL;
    }else{
        t->prev->next=t->next;
        t->next->prev=t->prev;
    }
    delete t;
}

void searchDLL(int key){
    Node* t=headDLL;
    while(t){
        if(t->data==key){
            cout<<"Found"<<endl;
            return;
        }
        t=t->next;
    }
    cout<<"Not Found"<<endl;
}

int sizeDLL(){
    int c=0;
    Node* t=headDLL;
    while(t){ c++; t=t->next;}
    return c;
}

bool palindromeDLL(){
    Node* l=headDLL;
    Node* r=tailDLL;
    while(l!=r && r->next!=l){
        if(l->data!=r->data) return false;
        l=l->next;
        r=r->prev;
    }
    return true;
}

void displayDLL(){
    Node* t=headDLL;
    while(t){ cout<<t->data<<" "; t=t->next;}
    cout<<endl;
}

struct CNode{
    int data;
    CNode* next;
};
CNode* headCLL=NULL;

void insertCLL(int x){
    CNode* n=new CNode{x,NULL};
    if(!headCLL){
        headCLL=n;
        n->next=n;
    }else{
        CNode* t=headCLL;
        while(t->next!=headCLL) t=t->next;
        t->next=n;
        n->next=headCLL;
    }
}

void deleteCLL(int key){
    if(!headCLL) return;
    CNode *t=headCLL,*p=NULL;
    do{
        if(t->data==key) break;
        p=t; t=t->next;
    }while(t!=headCLL);
    if(t->data!=key) return;
    if(t==headCLL && t->next==headCLL){
        headCLL=NULL;
        delete t;
        return;
    }
    if(t==headCLL){
        CNode* l=headCLL;
        while(l->next!=headCLL) l=l->next;
        headCLL=headCLL->next;
        l->next=headCLL;
        delete t;
        return;
    }
    p->next=t->next;
    delete t;
}

void searchCLL(int key){
    if(!headCLL){
        cout<<"Not Found"<<endl;
        return;
    }
    CNode* t=headCLL;
    do{
        if(t->data==key){
            cout<<"Found"<<endl;
            return;
        }
        t=t->next;
    }while(t!=headCLL);
    cout<<"Not Found"<<endl;
}

void displayCLL(){
    if(!headCLL) return;
    CNode* t=headCLL;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=headCLL);
    cout<<headCLL->data<<" "<<endl;
}

int sizeCLL(){
    if(!headCLL) return 0;
    int c=0;
    CNode* t=headCLL;
    do{ c++; t=t->next;}while(t!=headCLL);
    return c;
}

bool isCircular(){
    if(!headCLL) return false;
    CNode* slow=headCLL;
    CNode* fast=headCLL;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    int ch;
    while(true){
        cin>>ch;
        if(ch==1){
            int x,p; cin>>x>>p; insertDLL(x,p);
        }else if(ch==2){
            int key; cin>>key; deleteDLL(key);
        }else if(ch==3){
            int key; cin>>key; searchDLL(key);
        }else if(ch==4){
            displayDLL();
        }else if(ch==5){
            cout<<sizeDLL()<<endl;
        }else if(ch==6){
            cout<<(palindromeDLL()?"True":"False")<<endl;
        }else if(ch==7){
            int x; cin>>x; insertCLL(x);
        }else if(ch==8){
            int key; cin>>key; deleteCLL(key);
        }else if(ch==9){
            int key; cin>>key; searchCLL(key);
        }else if(ch==10){
            displayCLL();
        }else if(ch==11){
            cout<<sizeCLL()<<endl;
        }else if(ch==12){
            cout<<(isCircular()?"True":"False")<<endl;
        }else break;
    }
}