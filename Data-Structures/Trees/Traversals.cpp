#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void postorder(struct Node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data <<endl;
}

void inorder(struct Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data <<endl;
    inorder(node->right);
}

void preorder(struct Node *node)
{
    if (node == NULL)
        return;
    cout << node->data <<endl;
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(20);
    root->left->left = new Node(25);
    root->left->right = new Node(30);

    cout << "Preorder traversal of binary tree is" << endl;
    preorder(root);

    cout << "Inorder traversal of binary tree is" << endl;
    inorder(root);

    cout << "Postorder traversal of binary tree is" << endl;
    postorder(root);

    return 0;
}