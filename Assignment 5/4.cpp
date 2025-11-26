#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
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
    int n, x;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        insertEnd(x);
    }
    reverseList();
    displayList();
    return 0;
}
