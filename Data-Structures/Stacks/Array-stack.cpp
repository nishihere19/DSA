#include <bits/stdc++.h>
using namespace std;

bool isfull(int top, int n)
{
    if (top == n - 1)
        return true;
    else
        return false;
}

bool isempty(int top)
{
    if (top == -1)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cout << "Enter length of stack" << endl;
    cin >> n;
    int a[n], top = -1;
    int data;
    char ch = 'S';
    while (ch)
    {
        cout << "Type 'A' to add element, 'D' to pop element from stack. Press enter to quit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 'A':
        {
            cout << "Input element to be added in stack" << endl;
            cin >> data;
            if (isfull(top, n))
            {
                cout << "The stack is full" << endl;
            }
            else
            {
                (top)++;
                a[top] = data;
                cout << data << " added at " << top << endl;
            }
        }
        break;
        case 'D':
        {
            if (isempty(top))
            {
                cout << "The stack is empty!" << endl;
            }
            else
            {
                cout << "The element popped out is " << a[top] << endl;
                top--;
            }
        }
        break;

        default:
            break;
        }
    }
    //to output all elements in stack and pop one by one.
    while (top != -1)
    {
        if (isempty(top))
        {
            cout << "The stack is empty!" << endl;
            return 0;
        }
        cout << "The element popped out is " << a[top] << endl;
        top--;
    }
    return 0;
}
