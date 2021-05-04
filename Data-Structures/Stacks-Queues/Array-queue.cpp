#include <bits/stdc++.h> 
using namespace std; 
  
struct Queue { 
    int front, rear, capacity; 
    int* queue; 
    Queue(int c) 
    { 
        front = rear = 0; 
        capacity = c; 
        queue = new int; 
    }
    void enqueue(int data) 
    { 
        if (capacity == rear) { 
            cout<<"Queue is full"<<endl;
            return; 
        } 
        else { 
            queue[rear] = data; 
            rear++; 
        } 
        return; 
    } 
    void dequeue() 
    { 
        if (front == rear) { 
            cout<<"Queue is empty"<<endl; 
            return; 
        } 
        else { 
            for (int i = 0; i < rear - 1; i++) { 
                queue[i] = queue[i + 1]; 
            } 
            rear--; 
        } 
        return; 
    } 
    void show() 
    { 
        int i; 
        if (front == rear) { 
            cout<<"Queue is empty"<<endl;
            return; 
        } 
        for (i = front; i < rear; i++) { 
            cout<<queue[i]<<endl;
        } 
        return; 
    }
}; 
  
int main(void) 
{ 
    int c;
    cout<<"Enter capacity of queue"<<endl;
    cin>>c;
    Queue q(c); 
    q.show(); 
    char ch='s';
    while(ch){
        cout<<"Enter 'e' to enqueue, 'd' to dequeue, 's' to show elements in queue!"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 'e':
            cout<<"Enter element to be added."<<endl;
            cin>>c;
            q.enqueue(c); 
            break;
        case 'd':
            q.dequeue(); 
            break;
        case 's':
            q.show();
        default:
            break;
        }
    }
  
    return 0; 
} 