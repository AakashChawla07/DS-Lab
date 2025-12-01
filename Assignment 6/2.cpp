#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int value = 0) : val(value), next(NULL) {}
};
class CLL
{
    Node *head;
public:
    CLL(Node *head = NULL)
    {
        this->head = head;
    }
    void addBeg(int val)
    {
        Node *nn = new Node(val);
        if (head == NULL)
        {
            head = nn;
            head->next = nn;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = nn;
        nn->next = head;
        head = nn;
    }
    void addEnd(int val)
    {
        Node *nn = new Node(val);
        if(head == NULL){
            head = nn;
            head->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = nn;
        nn->next = head;
    }
    void deleteBeg()
    {
        if(head->next == head){
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        Node *temp2 = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        head = head->next;
        cout << "Deleted " << temp2->val << " !\n";
        delete temp2;
    }
    void deleteNode(int node)
    {
        if(head == NULL) return;
        if (head->val == node)
            deleteBeg();
        else
        {
            Node *temp = head->next;
            Node *prev = head;
            while (temp != head && temp->val != node)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == head)
            {
                cout << "Node not Found!\n";
                return;
            }
            prev->next = temp->next;
            cout << "Deleted " << temp->val << " !\n";
            delete temp;
        }
    }
    void printList()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        cout << "Circular L List : ";
        while (temp->next!= head)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << temp->val<<"->"<<temp->next->val << endl;
    }
};
int main()
{
    CLL list;
    list.addBeg(10);
    list.addBeg(30);
    list.addBeg(40);
    list.addEnd(100);
    list.addEnd(200);
    list.addEnd(300);
    list.printList();
    return 0;
}