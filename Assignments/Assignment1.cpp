#include <iostream>
using namespace std;

// Reuse the same Node structure
struct Node {
    int data;
    Node* next;
};


class Stack {

private:
    Node* top;   // points to the top node of the stack

public:
    Stack() { top = NULL; }   // constructor

    // Function to add a new element to the stack
    void push(int value) {
        // Create a new node and add it at the top
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;   // new node points to the old top
        top = newNode;         // update top pointer
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() const {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


class Queue {

private:
    Node* front;   // points to the first node
    Node* rear;    // points to the last node

public:
    Queue() {
        front = rear = NULL;
    }

    // Function to add a new element to the queue
    void enqueue(int value) {
        // Create a new node
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        // If queue is empty
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        // Add at the end
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display() const {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};



int main() {

    cout << "Stack output:" << endl;
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();   // Expected: 30 20 10

    cout << "\nQueue output:" << endl;
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();   // Expected: 10 20 30

    return 0;
}
