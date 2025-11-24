#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

Node* head=NULL;

void insertBegin(int x){
    Node* t=new Node(x);
    t->next=head;
    head=t;
}

void insertEnd(int x){
    Node* t=new Node(x);
    if(!head){ head=t; return; }
    Node* p=head;
    while(p->next) p=p->next;
    p->next=t;
}

void insertBefore(int val,int x){
    if(!head) return;
    if(head->data==val){
        insertBegin(x);
        return;
    }
    Node* p=head;
    while(p->next && p->next->data!=val) p=p->next;
    if(p->next){
        Node* t=new Node(x);
        t->next=p->next;
        p->next=t;
    }
}

void insertAfter(int val,int x){
    Node* p=head;
    while(p && p->data!=val) p=p->next;
    if(p){
        Node* t=new Node(x);
        t->next=p->next;
        p->next=t;
    }
}

void deleteBegin(){
    if(!head) return;
    Node* t=head;
    head=head->next;
    delete t;
}

void deleteEnd(){
    if(!head) return;
    if(!head->next){
        delete head;
        head=NULL;
        return;
    }
    Node* p=head;
    while(p->next->next) p=p->next;
    delete p->next;
    p->next=NULL;
}

void deleteValue(int val){
    if(!head) return;
    if(head->data==val){
        deleteBegin();
        return;
    }
    Node* p=head;
    while(p->next && p->next->data!=val) p=p->next;
    if(p->next){
        Node* t=p->next;
        p->next=t->next;
        delete t;
    }
}

int searchNode(int val){
    Node* p=head;
    int pos=1;
    while(p){
        if(p->data==val) return pos;
        pos++;
        p=p->next;
    }
    return -1;
}

void display(){
    Node* p=head;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int countDeleteKey(int key){
    int c=0;
    while(head && head->data==key){
        deleteBegin();
        c++;
    }
    Node* p=head;
    while(p && p->next){
        if(p->next->data==key){
            Node* t=p->next;
            p->next=t->next;
            delete t;
            c++;
        } else p=p->next;
    }
    return c;
}

int findMiddle(){
    Node* s=head;
    Node* f=head;
    while(f && f->next){
        s=s->next;
        f=f->next->next;
    }
    return s ? s->data : -1;
}

void reverseList(){
    Node* prev=NULL;
    Node* curr=head;
    while(curr){
        Node* nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
}

int main(){
    int choice,x,val,key;
    while(true){
        cin>>choice;
        if(choice==1){ cin>>x; insertBegin(x); }
        else if(choice==2){ cin>>x; insertEnd(x); }
        else if(choice==3){
            int type; cin>>type>>val>>x;
            if(type==0) insertBefore(val,x);
            else insertAfter(val,x);
        }
        else if(choice==4) deleteBegin();
        else if(choice==5) deleteEnd();
        else if(choice==6){ cin>>val; deleteValue(val); }
        else if(choice==7){ cin>>val; cout<<searchNode(val)<<"\n"; }
        else if(choice==8) display();
        else if(choice==9){
            cin>>key;
            cout<<countDeleteKey(key)<<"\n";
            display();
        }
        else if(choice==10) cout<<findMiddle()<<"\n";
        else if(choice==11){ reverseList(); display(); }
        else if(choice==0) break;
    }
}