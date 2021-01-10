#include<bits/stdc++.h>
using namespace std;
struct Node{   //NODE DEFINED
    int data;
    Node *next;
};

void push_at_start(Node **Head, int data){
    Node* t= new Node();         //MADE TEMPORARY NODE
    t->data=data;                 //ADDED DATA TO TEMP NODE
    t->next= (*Head);               //HEAD IS BEHIND TEMPORARY NODE
    *Head= t;                        //HEAD STARTS POINTING TO TEMPORARY NODE
}

void push_at_end(Node **Head, int data){
    Node* t= new Node();                    //MADE A TEMP NODE T
    t->data=data;
    Node* temp= new Node();                 //ANOTHER TEMP NODE...
    temp = *Head;                           //TEMP POINTS TO HEAD
    if(temp!=NULL){                         //CHECK IF LINKED LIST IS NOT EMPTY
        while(temp->next!=NULL){            //REACHES TILL LAST NODE
        //cout<<temp->data<<endl;
        temp= (temp->next);           
    } 
    temp->next= (t);                        //LINKED T TO THE LAST ELEMENT
    t->next= NULL;                          //LAST ELEMENT STARTS POINTING TO NULL
    }
    else{                                    //IF LINKED LIST IS EMPTY, WE DIRECTLY ADD T
        t->next= NULL;                       
        *Head= t;
    }
    
}

void pop_at_start(Node **Head){
    Node *temp= new Node();
    temp=*Head;
    if(temp==NULL){
        cout<<"LINKEDLIST IS EMPTY!"<<endl;
        return;
    }
    *Head=temp->next;
    cout<<"The element being deleted "<<temp->data<<endl;
    delete(temp);
    return;
}

void pop_at_end(Node **Head){
    Node *temp= new Node();
    Node *t= new Node();
    temp=*Head;
    if(temp==NULL){
        cout<<"LINKEDLIST IS EMPTY!"<<endl;
        return;
    }
    while(temp->next->next!=NULL) temp=temp->next;
    t=temp->next;
    temp->next=NULL;
    cout<<"The element being deleted "<<t->data<<endl;
    delete(t);
    return;
}

void check_pal_byStack(Node **Head){
    stack<int> check;
    Node *temp= new Node();
    temp= *Head;
    while(temp!=NULL){
        check.push(temp->data);
        
         //cout<<temp->data<<endl;
         temp=temp->next;
    }
    temp=*Head;
    while(temp->next!=NULL){
        if(check.top()!=temp->data){
            cout<<"Not Palindrome!"<<endl;
            return;
        }
        //cout<<temp->data<<endl;
        check.pop();
        temp=temp->next;
    }
    cout<<"Palindrome!"<<endl;
    return;
}
 int main(){
     struct Node *head= NULL;
     push_at_end(&head,20);
     push_at_end(&head,10);
     push_at_end(&head,30);
     push_at_end(&head,40);
     push_at_start(&head,40);
     push_at_start(&head,50);
     // THE OUTPUT SHOULD BE 50,40,20,10,30,40
     Node* temp= new Node();
     temp = head;
     cout<<"The linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     pop_at_start(&head);
     pop_at_end(&head);
     temp = head;
     cout<<"The linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     check_pal_byStack(&head);
     push_at_end(&head,10);
     push_at_end(&head,20);
     push_at_end(&head,40);
     temp = head;
     cout<<"Now the linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     check_pal_byStack(&head);
     return 0;
 }
