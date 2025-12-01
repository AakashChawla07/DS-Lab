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
    public:
    Node *head;
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
    void addAfter(int val, int target)
    {
        if(head == NULL){
            cout<<"EMPTY\n";
            return;
        }
        Node *nn = new Node(val);
        Node *temp = head;
        if (head->val != target)
        {
            temp = temp->next;
            while (temp != head && temp->val != target)
                temp = temp->next;
            if (temp == head)
            {
                cout << "Not found Target!\n";
                return;
            }
        }
        nn->next = temp->next;
        temp->next = nn;
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
    void searchNode(int target)
    {
        if(head==NULL)  return;
        Node *temp = head;
        do {
            if (temp->val == target) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
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
    int choice, val, target;
    do
    {
        cout << "Enter Choice:\n1. Insert beg  2. Insert End  3. Insert after node  4. Delete Node  5. Search Node  6. Print List  7. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> val;
            list.addBeg(val);
            break;
        case 2:
            cout << "Enter value : ";
            cin >> val;
            list.addEnd(val);
            break;
        case 3:
            cout << "Enter value and target : ";
            cin >> val >> target;
            list.addAfter(val, target);
            break;
        case 4:
            cout << "Enter value : ";
            cin >> val;
            list.deleteNode(val);
            break;
        case 5:
            cout << "Enter target : ";
            cin >> target;
            list.searchNode(target);
            break;
        case 6:
            list.printList();
            break;
        default:
            break;
        }

    } while (choice != 7);
    return 0;
}