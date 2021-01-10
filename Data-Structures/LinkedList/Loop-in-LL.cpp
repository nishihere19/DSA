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

void floyyd_loop_detect(Node **Head){
    Node *fast= new Node();
    Node *slow= new Node();
    slow=*Head; fast=slow->next->next;
    while(fast!=NULL&&fast->next!=NULL&&slow!=NULL) {
        if(fast==slow){
            cout<<"Loop detected"<<endl;
            return;
        }
        //cout<<"fast at "<<fast->data<<endl;
        //cout<<"slow at "<<slow->data<<endl;
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<"No loop detected"<<endl;

}

void push_to_make_loop(Node **Head, int data, int val){
    Node* temp= new Node();
    temp=*Head;
    int length=0;
    //cout<<length<<endl;
    while(temp->next!=NULL){
        temp=temp->next;
        length++;
        //cout<<temp->data<<endl;
    }
    //cout<<length<<endl;
    Node* t= new Node();
    t->data=data;
    temp->next=t;
    t->next= NULL;
    length++;
    int l=1;
    if(length<val){
        cout<<"The length is less than the desired value"<<endl;
        return;
    }
    temp=*Head;
    while(l<val&&temp!=NULL){
        temp=temp->next;
        l++;
    }
    cout<<"New node pointing to "<<temp->data<<endl;
    t->next=temp;
    return;
}

void hash_loop_detect(Node **Head){
    unordered_set<Node*>hash;
    Node* temp=new Node();
    temp= *Head;
    while(temp!=NULL){
        if(hash.find(temp)!=hash.end()){
            cout<<"Loop detected at "<<temp->data<<endl;
            return;
        }
        hash.insert(temp);
        temp=temp->next;
    }
    cout<<"No loop detected"<<endl;
}

void detect_remove_loop(Node **Head){
    unordered_set<Node*>hash;
    Node* temp=new Node();
    temp= *Head;
    Node* prev=new Node();
    while(temp!=NULL){
        if(hash.find(temp)!=hash.end()){
            cout<<"Loop detected at "<<temp->data<<endl;
            prev->next=NULL;
            cout<<"Loop removed!"<<endl;
            return;
        }
        hash.insert(temp);
        prev=temp;
        temp=temp->next;
    }
    cout<<"No loop detected"<<endl;
}

 int main(){
     struct Node *head= NULL;
     push_at_end(&head,20);
     push_at_end(&head,10);
     push_at_end(&head,30);
     push_at_end(&head,40);
     push_at_start(&head,40);
     push_at_start(&head,50);
     push_at_end(&head,20);
     push_at_end(&head,10);
     push_at_end(&head,30);
     Node* temp= new Node();
     temp = head;
     cout<<"The linkedlist is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
     cout<<"Implementing Floyyd's method:"<<endl;
     floyyd_loop_detect(&head);
     cout<<"Implementing hash method:"<<endl;
     hash_loop_detect(&head);
     cout<<"Made a loop at node 2"<<endl;
     push_to_make_loop(&head,5,2);
     cout<<"Implementing Floyyd's method:"<<endl;
     floyyd_loop_detect(&head);
     hash_loop_detect(&head);
     detect_remove_loop(&head);
     temp = head;
     cout<<"The linkedlist after loop removal is:"<<endl;
     while(temp!=NULL) {
         cout<<temp->data<<endl;
         temp= (temp->next);
     }
      return 0;
 }
