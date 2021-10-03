#include <bits/stdc++.h>
using namespace std;
struct Node
{ //NODE DEFINED
    int data;
    Node *next;
};

void push_at_start(Node **Head, int data)
{
    Node *t = new Node(); //MADE TEMPORARY NODE
    t->data = data;       //ADDED DATA TO TEMP NODE
    t->next = (*Head);    //HEAD IS BEHIND TEMPORARY NODE
    *Head = t;            //HEAD STARTS POINTING TO TEMPORARY NODE
}

void push_at_end(Node **Head, int data)
{
    Node *t = new Node(); //MADE A TEMP NODE T
    t->data = data;
    Node *temp = new Node(); //ANOTHER TEMP NODE...
    temp = *Head;            //TEMP POINTS TO HEAD
    if (temp != NULL)
    { //CHECK IF LINKED LIST IS NOT EMPTY
        while (temp->next != NULL)
        { //REACHES TILL LAST NODE
            //cout<<temp->data<<endl;
            temp = (temp->next);
        }
        temp->next = (t); //LINKED T TO THE LAST ELEMENT
        t->next = NULL;   //LAST ELEMENT STARTS POINTING TO NULL
    }
    else
    { //IF LINKED LIST IS EMPTY, WE DIRECTLY ADD T
        t->next = NULL;
        *Head = t;
    }
}

void pop_at_start(Node **Head)
{
    Node *temp = new Node();
    temp = *Head;
    if (temp == NULL)
    {
        cout << "LINKEDLIST IS EMPTY!" << endl;
        return;
    }
    *Head = temp->next;
    cout << "The element being deleted " << temp->data << endl;
    delete (temp);
    return;
}

void pop_at_end(Node **Head)
{
    Node *temp = new Node();
    Node *t = new Node();
    temp = *Head;
    if (temp == NULL)
    {
        cout << "LINKEDLIST IS EMPTY!" << endl;
        return;
    }
    while (temp->next->next != NULL)
        temp = temp->next;
    t = temp->next;
    temp->next = NULL;
    cout << "The element being deleted " << t->data << endl;
    delete (t);
    return;
}

int sumLinkedlist(struct Node *p) //recursive function for calculating sum is defined
{
    if (p) //this condition will be executed and will be true till the p->next!=0
    {
        return sumLinkedlist(p->next) + p->data; //here the function is being recursively called with the pointer poiting to next the the data value is being added
    }
    else //when the linked list reached the last node then the function will return 0
        return 0;
}

int main()
{
    struct Node *head = NULL;
    push_at_end(&head, 20);
    push_at_end(&head, 10);
    push_at_end(&head, 30);
    push_at_end(&head, 40);
    push_at_start(&head, 40);
    push_at_start(&head, 50);
    // THE OUTPUT SHOULD BE 50,40,20,10,30,40
    Node *temp = new Node();
    temp = head;
    cout << "The linkedlist is:" << endl;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = (temp->next);
    }
    cout << "Sum of all the elements of linked list is: " << sumLinkedlist(head) << endl;
    pop_at_start(&head);
    pop_at_end(&head);
    temp = head;
    cout << "The linkedlist is:" << endl;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = (temp->next);
    }
    cout << "Sum of all the elements of linked list is: " << sumLinkedlist(head) << endl;
    return 0;
}
