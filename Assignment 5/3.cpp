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

void findMiddle() {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;
}

int main() {
    int n, x;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        insertEnd(x);
    }
    findMiddle();
    return 0;
}
