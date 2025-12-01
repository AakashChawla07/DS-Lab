#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int value = 0) : val(value), prev(NULL), next(NULL) {}
};
class DLL {
    public:
    Node* head;
    Node* tail;

    DLL() {
        head = NULL;
        tail = NULL;
    }
    void addBeg(int val) {
        Node* nn = new Node(val);

        if (head == NULL) {        
            head = tail = nn;
            return;
        }

        nn->next = head;
        head->prev = nn;
        head = nn;
    }
    void addEnd(int val) {
        Node* nn = new Node(val);

        if (head == NULL) {  
            head = tail = nn;
            return;
        }
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
    void addAfter(int val, int target) {
        if (head == NULL) {
            cout << "EMPTY\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->val != target)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Target not found!\n";
            return;
        }

        Node* nn = new Node(val);
        nn->next = temp->next;
        nn->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = nn;
        else
            tail = nn;
        

        temp->next = nn;
    }
    void deleteBeg() {
        Node* temp = head;
        if (head == tail) {
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

    void deleteNode(int value) {
        if (head == NULL) {
            cout << "EMPTY\n";
            return;
        }
        if (head->val == value) {
            deleteBeg();
            return;
        }

        Node* temp = head->next;

        while (temp != NULL && temp->val != value)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node not found!\n";
            return;
        }
        if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        cout << "Deleted " << temp->val << " !\n";
        delete temp;
    }

    void searchNode(int target) {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->val != target)
            temp = temp->next;

        if (temp != NULL)
            cout << "Node found!\n";
        else
            cout << "Node not found!\n";
    }
    void printList() {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }

        cout << "Doubly Linked List (forward): ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main()
{
    DLL list;
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