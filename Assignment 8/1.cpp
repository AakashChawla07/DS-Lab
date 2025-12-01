#include<iostream>
using namespace std;    
class Node{
    public:
    int val;
    Node *left,*right;
    Node(int value):val(value),left(NULL),right(NULL)
    {}
};
void preorder(Node *root)
{
    if(root==NULL)
    return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main()
{
    Node *root=new Node(11);
    Node *a=new Node(10);
    Node *b=new Node(55);
    Node *c=new Node(78);
    Node *d=new Node(51);
    Node *e=new Node(9);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->right=e;
    cout<<"Preorder Traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    postorder(root);
    cout<<endl;
    return 0;
}