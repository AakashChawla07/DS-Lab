#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertEnd(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        return;
    }
    Node* p = head;
    while(p->next != NULL) p = p->next;
    p->next = temp;
}

void insertBefore(int val, int x) {
    if(head == NULL) return;
    if(head->data == val) {
        insertBeginning(x);
        return;
    }
    Node* p = head;
    while(p->next != NULL && p->next->data != val) p = p->next;
    if(p->next == NULL) return;
    Node* temp = new Node;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}

void insertAfter(int val, int x) {
    Node* p = head;
    while(p != NULL && p->data != val) p = p->next;
    if(p == NULL) return;
    Node* temp = new Node;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}

void deleteBeginning() {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if(head == NULL) return;
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* p = head;
    while(p->next->next != NULL) p = p->next;
    delete p->next;
    p->next = NULL;
}

void deleteValue(int val) {
    if(head == NULL) return;
    if(head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* p = head;
    while(p->next != NULL && p->next->data != val) p = p->next;
    if(p->next == NULL) return;
    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
}

void searchValue(int val) {
    Node* p = head;
    int pos = 1;
    while(p != NULL) {
        if(p->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found" << endl;
}

void displayList() {
    Node* p = head;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int choice, val, x;
    while(true) {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert Before a Node\n4. Insert After a Node\n5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n8. Search\n9. Display\n10. Exit\n";
        cin >> choice;
        if(choice == 10) break;
        switch(choice) {
            case 1: cin >> val; insertBeginning(val); break;
            case 2: cin >> val; insertEnd(val); break;
            case 3: cin >> val >> x; insertBefore(val, x); break;
            case 4: cin >> val >> x; insertAfter(val, x); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> val; deleteValue(val); break;
            case 8: cin >> val; searchValue(val); break;
            case 9: displayList(); break;
        }
    }
    return 0;
}
