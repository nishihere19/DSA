#include<bits/stdc++.h>
using namespace std;

class myQueue{
    stack<int> s1,s2;
    public:
    void enqueue(int k);
    void dequeue();
    int front();
    int rear();
};

void myQueue::enqueue(int k){
    cout<<"Enqueued "<<k<<endl;
    s2.push(k);
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    stack<int> temp;
    temp=s1;
    s1=s2;
    s2=temp;
}

void myQueue::dequeue(){
    if(s1.empty()){
        cout<<"Queue is empty!"<<endl;
        return;
    }
    cout<<"Removing "<<s1.top()<<endl;
    s1.pop();
}

int myQueue::front(){
    if(!s1.empty()) return s1.top();
    return -1;
}

int myQueue::rear(){
    if(s1.empty()) return -1;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    int rear_val=s2.top();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return rear_val;
}
int main(){
    myQueue q;
    cout<<q.front()<<endl;
    cout<<q.rear()<<endl;
    q.dequeue();
    q.enqueue(2);
    q.enqueue(4);
    cout<<q.front()<<endl;
    cout<<q.rear()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}