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
int main()
{
    Node root(20);
    Node a(33);
    Node b(44);
    Node c(51);
    Node d(60);
    Node e(77);
    root.left=&a;
    root.right=&b;
    a.left=&c;
    b.left=&d;
    b.right=&e;
    int num;
    cout<<"Enter the number to be searched: ";
    cin>>num;
    Node* found=recSearch(&root,num);
    if(found)
    cout<<"Found!"<<endl;
    else
    cout<<"Not Found!"<<endl;
    found=itSearch(&root,num);
    if(found)
    cout<<"Found!"<<endl;
    else
    cout<<"Not Found!"<<endl;
    return 0;
}