#include <iostream>
using namespace std;
class Node
{
public:
    char val;
    Node *prev;
    Node *next;

    Node(int value = 0) : val(value), prev(NULL), next(NULL) {}
};
class DLL
{
public:
    Node *head;
    Node *tail;

    DLL()
    {
        head = NULL;
        tail = NULL;
    }
    void addBeg(char val)
    {
        Node *nn = new Node(val);

        if (head == NULL)
        {
            head = tail = nn;
            return;
        }

        nn->next = head;
        head->prev = nn;
        head = nn;
    }
    void addEnd(char val)
    {
        Node *nn = new Node(val);

        if (head == NULL)
        {
            head = tail = nn;
            return;
        }
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
    void deleteBeg()
    {
        Node *temp = head;
        if (head == tail)
        {
            cout << "Deleted " << temp->val << " !\n";
            head = tail = NULL;
            delete temp;
            return;
        }
        head = head->next;
        head->prev = NULL;
        cout << "Deleted " << temp->val << " !\n";
        delete temp;
    }

    void deleteNode(char value)
    {
        if (head == NULL)
        {
            cout << "EMPTY\n";
            return;
        }
        if (head->val == value)
        {
            deleteBeg();
            return;
        }

        Node *temp = head->next;

        while (temp != NULL && temp->val != value)
            temp = temp->next;
        if (temp == NULL)
        {
            cout << "Node not found!\n";
            return;
        }
        if (temp == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        cout << "Deleted " << temp->val << " !\n";
        delete temp;
    }
    void printList()
    {
        if (head == NULL)
        {
            cout << "List empty!\n";
            return;
        }

        cout << "Doubly Linked List (forward): ";
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
bool checkPalin(DLL l)
{
    char ch;
    Node *left = l.head;
    Node *right = l.tail;
    while(left != NULL && right != NULL)
    {
        if (left == right)
            return true;
        ch = left->val;
        left = left->next;
        if (ch != right->val)
            return false;
        if (left == right)
            return true;
        right = right->prev;
    }
    return true;
}
int main() {
    DLL list;
    list.addEnd('R');
    list.addEnd('A');
    list.addEnd('D');
    list.addEnd('A');
    list.addEnd('R');
    list.printList();
    if (checkPalin(list))
        cout << "YES, it is a palindrome!\n";
    else
        cout << "NO, it is not a palindrome!\n";
    return 0;
}