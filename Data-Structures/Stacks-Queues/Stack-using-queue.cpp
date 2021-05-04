#include<bits/stdc++.h>
using namespace std;

class myStack{
    queue<int>q1,q2;
    int size;
    public:
    myStack(){
        size = 0;
    }
    void push(int k);
    void pop();
    int top();
    int stack_size();
};

void myStack::push(int k){
    cout<<"Pushing "<<k<<endl;
    q2.push(k);
    size++;
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> temp;
    temp=q1;
    q1=q2;
    q2=temp;
}

void myStack::pop(){
    if(q1.empty()){
        cout<<"Stack underflow"<<endl;
        return;
    }
    cout<<"Deleting "<<q1.front()<<endl;
    q1.pop();
    size--;
}

int myStack::top(){
    if(q1.empty()) return -1;
    return(q1.front());
}

int myStack::stack_size(){
    return size;
}

int main(){
    myStack S;
    cout<<S.top()<<endl;
    S.push(1);
    S.push(2);
    cout<<S.top()<<endl;
    S.stack_size();
    S.pop();
    S.pop();
    S.pop();
    return 0;
}