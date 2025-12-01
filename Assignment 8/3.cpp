#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *left,*right;
    Node(int value):val(value),left(NULL),right(NULL)
    {}
};
Node* insert(Node* root, int value) 
{
    if (root==NULL)
    return new Node(value);
    if (value < root->val)
        root->left=insert(root->left, value);
    else if(value>root->val)
        root->right = insert(root->right, value);
    return root;
}
Node* min(Node* root) 
{
    while (root->left!=NULL)
        root=root->left;
    return root;
}
Node* deleteNode(Node* root, int target) 
{
    if (root == NULL)
        return NULL;

    if (target < root->val) {
        root->left = deleteNode(root->left, target);
    }
    else if (target > root->val) {
        root->right = deleteNode(root->right, target);
    }
    else 
    {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = min(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}
int maxDepth(Node *root)
{
    if (root==NULL || root->left==NULL && root->right==NULL)
    return 0;           
    return (1+max(maxDepth(root->left),maxDepth(root->right)));
}
int minDepth(Node *root)
{
    if (root==NULL || root->left==NULL && root->right==NULL) 
    return 0;      
    if (root->left==NULL)
    return (1+minDepth(root->right));
    if (root->right==NULL)
    return (1+minDepth(root->left));
    return (1+min(minDepth(root->left),minDepth(root->right)));
}
void inorder(Node* root) 
{
    if (root==NULL) 
    return;
    inorder(root->left);
    cout<<root->val<< " ";
    inorder(root->right);
}
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "Inorder Traversal before deletion: ";
    inorder(root);
    cout << endl;
    root = deleteNode(root, 70);
    cout << "Inorder Traversal after deletion: ";
    inorder(root);
    cout << endl;
    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;
    return 0;
}
