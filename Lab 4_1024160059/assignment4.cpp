#include <bits/stdc++.h>
using namespace std;

class SimpleQueue {
public:
    int arr[100], front, rear, n;
    SimpleQueue(int size){ n=size; front=rear=-1; }
    bool isFull(){ return rear==n-1; }
    bool isEmpty(){ return front==-1 || front>rear; }
    void enqueue(int x){
        if(isFull()) return;
        if(front==-1) front=0;
        arr[++rear]=x;
    }
    int dequeue(){
        if(isEmpty()) return -1;
        return arr[front++];
    }
    int peek(){
        if(isEmpty()) return -1;
        return arr[front];
    }
    void display(){
        if(isEmpty()) return;
        for(int i=front;i<=rear;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
};

class CircularQueue {
public:
    int arr[100], front, rear, n;
    CircularQueue(int size){ n=size; front=rear=-1; }
    bool isFull(){ return (rear+1)%n==front; }
    bool isEmpty(){ return front==-1; }
    void enqueue(int x){
        if(isFull()) return;
        if(front==-1) front=0;
        rear=(rear+1)%n;
        arr[rear]=x;
    }
    int dequeue(){
        if(isEmpty()) return -1;
        int x=arr[front];
        if(front==rear){ front=rear=-1; }
        else front=(front+1)%n;
        return x;
    }
    int peek(){
        if(isEmpty()) return -1;
        return arr[front];
    }
    void display(){
        if(isEmpty()) return;
        int i=front;
        while(true){
            cout<<arr[i]<<" ";
            if(i==rear) break;
            i=(i+1)%n;
        }
        cout<<"\n";
    }
};

vector<int> interleaveQueue(vector<int> q){
    int n=q.size();
    queue<int> a,b;
    for(int i=0;i<n/2;i++) a.push(q[i]);
    for(int i=n/2;i<n;i++) b.push(q[i]);
    vector<int> ans;
    while(!a.empty() && !b.empty()){
        ans.push_back(a.front()); a.pop();
        ans.push_back(b.front()); b.pop();
    }
    return ans;
}

vector<char> firstNonRepeating(string s){
    queue<char> q;
    vector<int> f(256,0);
    vector<char> ans;
    for(char c:s){
        q.push(c);
        f[c]++;
        while(!q.empty() && f[q.front()]>1) q.pop();
        if(q.empty()) ans.push_back('-');
        else ans.push_back(q.front());
    }
    return ans;
}

class StackTwoQ {
public:
    queue<int> q1,q2;
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    int pop(){
        if(q1.empty()) return -1;
        int x=q1.front(); q1.pop();
        return x;
    }
    int top(){
        if(q1.empty()) return -1;
        return q1.front();
    }
    bool empty(){ return q1.empty(); }
};

class StackOneQ {
public:
    queue<int> q;
    void push(int x){
        q.push(x);
        int s=q.size();
        while(s>1){
            q.push(q.front());
            q.pop();
            s--;
        }
    }
    int pop(){
        if(q.empty()) return -1;
        int x=q.front(); q.pop();
        return x;
    }
    int top(){
        if(q.empty()) return -1;
        return q.front();
    }
    bool empty(){ return q.empty(); }
};

int main(){
    SimpleQueue sq(100);
    CircularQueue cq(100);

    while(true){
        int ch;
        cin>>ch;

        if(ch==1){
            int x; cin>>x; sq.enqueue(x);
        }
        else if(ch==2){
            cout<<sq.dequeue()<<"\n";
        }
        else if(ch==3){
            sq.display();
        }
        else if(ch==4){
            int x; cin>>x; cq.enqueue(x);
        }
        else if(ch==5){
            cout<<cq.dequeue()<<"\n";
        }
        else if(ch==6){
            cq.display();
        }
        else if(ch==7){
            int n; cin>>n;
            vector<int> v(n);
            for(int i=0;i<n;i++) cin>>v[i];
            vector<int> r = interleaveQueue(v);
            for(int x:r) cout<<x<<" ";
            cout<<"\n";
        }
        else if(ch==8){
            string s; cin>>s;
            vector<char> r = firstNonRepeating(s);
            for(char c:r) cout<<c<<" ";
            cout<<"\n";
        }
        else if(ch==9){
            StackTwoQ st;
            int k; cin>>k;
            while(k--){
                int x; cin>>x;
                st.push(x);
            }
            while(!st.empty()){
                cout<<st.pop()<<" ";
            }
            cout<<"\n";
        }
        else if(ch==10){
            StackOneQ st;
            int k; cin>>k;
            while(k--){
                int x; cin>>x;
                st.push(x);
            }
            while(!st.empty()){
                cout<<st.pop()<<" ";
            }
            cout<<"\n";
        }
        else if(ch==0){
            break;
        }
    }
}