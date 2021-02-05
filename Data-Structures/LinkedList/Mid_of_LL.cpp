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

void simple_method_mid(Node **Head){
    int length=0;
    Node* temp=new Node;
    temp= *Head;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    temp=*Head;
    if(length%2!=0){
        for(int i=0;i<(length/2);i++){
        temp=temp->next;
    }
    cout<<"The mid element is "<<temp->data<<endl;
    }
    else{
        
        for(int i=0;i<(length/2)-1;i++){
        temp=temp->next;
    }
    cout<<"The mid elements are "<<temp->data<<" and "<<temp->next->data<<endl;
    
    }
}
void second_mid_method(Node **Head){
    Node* fast= new Node;
    Node* slow= new Node;
    fast=slow=*Head;
    int flag=0;
    while(fast->next!=NULL){
        //cout<<fast->data;
        if(fast->next->next==NULL) {
            flag=1;
            break;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    if(flag==1){
        cout<<"The mid element here are "<<slow->data<<" and "<<slow->next->data<<endl;
    }
    else cout<<"The mid element here is "<<slow->data<<endl;
    
}

 int main(){
     struct Node *head= NULL;
     push_at_end(&head,20);
     push_at_end(&head,10);
     push_at_end(&head,30);
     push_at_end(&head,40);
     push_at_start(&head,40);
     push_at_start(&head,50);
     //push_at_start(&head,60);
     // THE OUTPUT SHOULD BE 50,40,20,10,30,40
     Node* temp= new Node();
     temp = head;
     cout<<"The linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     simple_method_mid(&head);
     second_mid_method(&head);
     push_at_start(&head,60);
     temp = head;
     cout<<"The linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     simple_method_mid(&head);
     second_mid_method(&head);
     return 0;
 }
