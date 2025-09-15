#include <iostream>
using namespace std;

#define MAX 4

struct Queue {
    int queue[MAX];
    int front,rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear-front == MAX - 1;
    }

    void enqueue(int value) {
        if (isFull()) 
            cout << "Queue Overflow\n";
        else
        queue[(++rear%MAX)] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -999;
        }
        return queue[(front++%MAX)];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -999;
        }
        return queue[(front%MAX)];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i%MAX] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice,r;

    do {
        cout << "\nChoose one: \n";
        cout << "1. Enqueue  2. Dequeue  3. Peek  4. Display  5. Check if Empty  6. Check if Full  7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                int value;
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                r =q.dequeue();
                if(r!=-999)
                cout<<"Removed element: "<<r;
                break;
            case 3:
                r = q.peek();
                if(r!=-999)
                cout<<"Top element: "<<r;
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty()) cout << "Queue is empty\n";
                else cout << "Queue is not empty\n";
                break;
            case 6:
                if (q.isFull()) cout << "Queue is full\n";
                else cout << "Queue is not full\n";
                break;
            case 0:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
