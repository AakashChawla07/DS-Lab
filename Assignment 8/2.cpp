#include<iostream>
using namespace std;    
class Node{
    public:
    int val;
    Node *left,*right;
    Node(int value):val(value),left(NULL),right(NULL)
    {}
};
Node* recSearch(Node* root,int target) 
{
    Node* temp=root;
    if (temp==NULL||temp->val==target)
    return temp;
    if (target<temp->val)
    return recSearch(temp->left, target);
    else
    return recSearch(temp->right, target);
}
Node* itSearch(Node* root,int target) 
{
    Node* temp =root;
    while (temp!=NULL) 
    {
        if (temp->val==target)
        return temp;
        else if (target<temp->val)
        temp=temp->left;
        else
        temp=temp->right;
    }
    return NULL;
}
Node* max(Node* root) 
{
    if (root==NULL)
    return NULL;
    if (root->right==NULL)
    return root;
    return max(root->right);
}
Node* min(Node* root) 
{
    if (root==NULL)
    return NULL;
    while (root->left!=NULL)
        root=root->left;
    return root;
}
Node* inSucc(Node* root, Node* x) 
{
    if (x->right!=NULL)
    return min(x->right);

    Node* suc=NULL;
    while (root!=NULL) 
    {
        if (x->val<root->val) 
        {
            suc=root;  
            root=root->left;
        }
        else if (x->val>root->val)
            root=root->right;
        else
            break;
    }
    return suc;
}
Node* inPred(Node* root, Node* x) 
{
    if (x->left!=NULL)
    return max(x->left);
    Node* pred=NULL;
    while (root!=NULL) 
    {
        if (x->val > root->val) 
        {
            pred=root;          
            root=root->right;
        }
        else if (x->val<root->val)
        root=root->left;
        else
        break;
    }
    return pred;
}
int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    int xx = 40;
    Node* res1 = recSearch(root, xx);
    if(res1 != NULL)
        cout << "Recursive Search: Found " << xx << endl;
    else
        cout << "Recursive Search: " << xx << " not found!" << endl;
    xx = 70;
    Node* res2 = itSearch(root, xx);
    if(res2 != NULL)
        cout << "Iterative Search: Found " << xx << endl;
    else
        cout << "Iterative Search: " << xx << " not found!" << endl;
    Node* maxNode = max(root);
    if(maxNode != NULL)
        cout << "Max value in BST: " << maxNode->val << endl;
    Node* minNode = min(root);
    if(minNode != NULL)
        cout << "Min value in BST: " << minNode->val << endl;
    Node* x = root->left->right;
    Node* successor = inSucc(root, x);
    if(successor != NULL)
        cout << "Inorder Successor of " << x->val << ": " << successor->val << endl;
    else
        cout << "No Inorder Successor for " << x->val << endl;
    Node* y = root->right;
    Node* predecessor = inPred(root, y);
    if(predecessor != NULL)
        cout << "Inorder Predecessor of " << y->val << ": " << predecessor->val << endl;
    else
        cout << "No Inorder Predecessor for " << y->val << endl;
    return 0;
}
