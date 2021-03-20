#include<bits/stdc++.h>
using namespace std;
struct Node{   //NODE DEFINED
    int data;
    Node *next;
    Node *prev;
};

void push_at_start(Node **Head, int data){
    Node* t= new Node();         //MADE TEMPORARY NODE
    (*Head)->prev=t;             //ADDED NEW NODE TO PREVIOUS OF HEAD
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
    t->prev=temp;
    t->next= NULL;                          //LAST ELEMENT STARTS POINTING TO NULL
    }
    else{                                    //IF LINKED LIST IS EMPTY, WE DIRECTLY ADD T
        t->next= NULL;   
        t->prev=NULL;                    
        *Head= t;
    }
    
}

void push_at_nth(Node **Head, int data, int n){
    Node* t= new Node();         //MADE TEMPORARY NODE
    Node* temp= new Node();
    temp=(*Head);
    int counter=1;
    while(counter<n){
        temp=temp->next;
        counter++;
        if(counter<n&&temp==NULL){
            cout<<"The length of the doubly Linkedlist is less than the index at which node is to be added!"<<endl;
            return;
        }
    }
    temp->prev->next=t;      //TEMP POINTS TO NTH NODE, LINK NEW NODE TO TEMP'S PREVIOUS
    t->prev=temp->prev;         //ADD PREVIOUS TO NEW NODE'S PREVIOUS
    temp->prev=t;             //ADDED NEW NODE TO PREVIOUS OF TEMP
    t->data=data;                 //ADDED DATA TO TEMP NODE
    t->next= temp;               //THE LINKED LIST SHIFTS BY ONE NODE
    if(t->prev==NULL) *Head=t;      //CHECK IF THE INSERTION IS AT FIRST NODE
}

void pop_at_start(Node **Head){
    Node *temp= new Node();
    temp=*Head;
    if(temp==NULL){
        cout<<"LINKEDLIST IS EMPTY!"<<endl;
        return;
    }
    if(temp->next==NULL){
        cout<<"The element being deleted is "<<temp->data<<endl;
        *Head=NULL;
        delete(temp);
        return;
    }
    temp->next->prev=NULL;
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
     cout<<"The doubly linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     pop_at_start(&head);
     pop_at_end(&head);
     temp = head;
     cout<<"The doubly linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     push_at_nth(&head,5,2);
     temp = head;
     cout<<"The doubly linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     push_at_nth(&head,15,7);
     return 0;
 }
