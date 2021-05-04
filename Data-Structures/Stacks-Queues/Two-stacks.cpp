#include<bits/stdc++.h>
using namespace std;

class TwoStack{
    int* arr;
    int top1;
    int top2;
    int n;
    public:
    TwoStack(int n){
        arr = new int[n];
        top1=-1;
        top2=n;

    }
    void push1(int k);
    void push2(int k);
    void pop1();
    void pop2();
};

void TwoStack::push1(int k){
if(top1<top2&&top1!=top2-1){
    top1++;
    arr[top1]=k;
}
else cout<<"Stack1 Overflow"<<endl;
}

void TwoStack::push2(int k){
if(top1<top2&&top1!=top2-1){
    top2--;
    arr[top2]=k;
}
else cout<<"Stack2 Overflow"<<endl;
}

void TwoStack::pop1(){
    if(top1>-1){
        top1--;
    }
    else cout<<"Stack1 underflow"<<endl;
}

void TwoStack::pop2(){
    if(top2<n){
        top2++;
    }
    else cout<<"Stack2 Underflow"<<endl;
}

int main(){
    TwoStack mystack(4);
    mystack.push1(1);
    mystack.push1(2);
    mystack.push1(3);
    mystack.push2(4);
    mystack.push2(9);
    mystack.push1(4);
    mystack.pop1();
    mystack.pop2();
    mystack.pop1();
    mystack.pop1();
    mystack.pop1();
    mystack.pop2();

    return 0;
}