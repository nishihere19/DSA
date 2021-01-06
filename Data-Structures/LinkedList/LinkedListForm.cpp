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

void nth_node_from_end(Node **Head, int n){
    int length=0; //TO CALCULATE LENGTH OF LINKEDLIST
    Node *temp = *Head;
    if(temp==NULL){
        cout<<"LinkedList was empty";
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
        length++;
    }
    temp=*Head;
    if(n>length){
        cout<<"Length of linkedlist is less than input"<<endl;
        return;
    }
    else{
        for(int i=0;i<length-n+1;i++){
            temp=temp->next;
        }
        cout<<temp->data<<endl;

    }
    return;
}
void nth_node_from_start(Node **Head, int n){
    int length=0; //TO CALCULATE LENGTH OF LINKEDLIST
    Node *temp = *Head;
    if(temp==NULL){
        cout<<"LinkedList was empty";
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
        length++;
    }
    temp=*Head;
    if(n>length){
        cout<<"Length of linkedlist is less than input"<<endl;
        return;
    }
    else{
        for(int i=0;i<n-1;i++){
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
    return;
}

void reverse(Node **Head){
    Node *prev=new Node();
    Node *next= new Node();
    Node *curr= new Node();
    curr=*Head;
    next=curr->next;
    prev= NULL;
    while(next!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        *Head=next;
        next=next->next;
        //cout<<prev->data<<curr->data<<next->data<<endl;
    }
    curr->next=prev;
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

    cout<<"The nth nodes based on input are"<<endl;
    nth_node_from_start(&head,2);
    nth_node_from_end(&head,2);
    nth_node_from_end(&head,1);
    nth_node_from_start(&head,1);
    nth_node_from_end(&head,5);
    nth_node_from_start(&head,5);

    reverse(&head);
     //Node* temp= new Node();
     temp = head;
     //cout<<temp->next<<endl;
     cout<<"The reversed LinkedList is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }

 }
