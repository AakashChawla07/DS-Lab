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

int deleteAll(int key) {
    int count = 0;
    while(head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* p = head;
    while(p != NULL && p->next != NULL) {
        if(p->next->data == key) {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
            count++;
        } else {
            p = p->next;
        }
    }
    return count;
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
    int n, x, key;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        insertEnd(x);
    }
    cin >> key;
    int count = deleteAll(key);
    cout << "Occurrences deleted: " << count << endl;
    displayList();
    return 0;
}
