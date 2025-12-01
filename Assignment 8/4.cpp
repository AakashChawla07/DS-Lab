#include <iostream>
#include <climits> 
using namespace std;
class Node{
    public:
    int val;
    Node *left,*right;
    Node(int value):val(value),left(NULL),right(NULL)
    {}
};
bool isBST(Node* root, int minVal,int maxVal)
{
    if (root==NULL)
    return true;
    if (root->val<=minVal||root->val>=maxVal)
    return false;
    return (isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal));
}
int main() 
{
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    if (isBST(root,INT_MIN,INT_MAX))
    cout<<"The tree is a BST!"<<endl;
    else
    cout<<"The tree is NOT a BST!"<<endl;
    return 0;
}