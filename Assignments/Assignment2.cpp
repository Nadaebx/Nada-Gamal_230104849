#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class Stack {

private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Destructor - clear all nodes
    ~Stack() {
        while (top != NULL) {
            pop();
        }
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == NULL;
    }

    // push() already implemented in Homework 1
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // NEW: pop() – required in Homework 2
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to pop." << endl;
            return -1; // or throw an exception
        }

        Node* temp = top;
        int removedValue = temp->data;

        top = top->next;
        delete temp;

        return removedValue;
    }

    // NEW: peek() – view top node
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return top->data;
    }

    // Display all stack elements
    void display() const {
        if (isEmpty()) {
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
    Node* frontPtr;
    Node* rearPtr;

public:
    // Constructor
    Queue() {
        frontPtr = rearPtr = NULL;
    }

    // Destructor
    ~Queue() {
        while (frontPtr != NULL) {
            dequeue();
        }
    }

    // Check if empty
    bool isEmpty() const {
        return frontPtr == NULL;
    }

    // enqueue() already implemented
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()) {
            frontPtr = rearPtr = newNode;
            return;
        }

        rearPtr->next = newNode;
        rearPtr = newNode;
    }

    // NEW: dequeue() – required in Homework 2
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to dequeue." << endl;
            return -1;
        }

        Node* temp = frontPtr;
        int removedValue = temp->data;

        frontPtr = frontPtr->next;

        if (frontPtr == NULL) { // queue became empty
            rearPtr = NULL;
        }

        delete temp;

        return removedValue;
    }

    // NEW: front() – view first element
    int front() const {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return frontPtr->data;
    }

    // Display queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = frontPtr;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {

    cout << "=== Testing Stack ===" << endl;
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Popped: " << s.pop() << endl;
    s.display();

    cout << "Top element: " << s.peek() << endl;

    cout << "\n=== Testing Queue ===" << endl;
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Front element: " << q.front() << endl;

    return 0;
}
