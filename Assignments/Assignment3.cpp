#include <iostream>
#include <string>
using namespace std;


class Stack {
private:
    int arr[100];        // stack array
    int top;             // index of top element
    int capacity;        // max size of stack

public:
    Stack(int size = 100) {
        capacity = size;
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Error: Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
};


int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


string infixToPostfix(string exp) {
    Stack s;
    string postfix = "";

    for (char c : exp) {

        // Ignore spaces
        if (c == ' ') continue;

        // Case: digit (operand)
        if (isdigit(c)) {
            postfix += c;
            postfix += " ";
        }
        // Case: opening parenthesis
        else if (c == '(') {
            s.push(c);
        }
        // Case: closing parenthesis
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += (char)s.pop();
                postfix += " ";
            }
            if (s.isEmpty()) {
                return "Error: Mismatched parentheses!";
            }
            s.pop(); // remove '('
        }
        // Case: operator
        else if (isOperator(c)) {
            while (!s.isEmpty() &&
                   precedence((char)s.peek()) >= precedence(c)) {
                postfix += (char)s.pop();
                postfix += " ";
            }
            s.push(c);
        }
        else {
            return "Error: Invalid character in expression!";
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        if (s.peek() == '(') return "Error: Mismatched parentheses!";
        postfix += (char)s.pop();
        postfix += " ";
    }

    return postfix;
}


int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {

        char c = exp[i];

        if (c == ' ') continue;

        // Operand (digit)
        if (isdigit(c)) {
            s.push(c - '0');
        }
        // Operator
        else if (isOperator(c)) {
            if (s.isEmpty()) {
                cout << "Error: Not enough operands!" << endl;
                return -1;
            }
            int b = s.pop();
            if (s.isEmpty()) {
                cout << "Error: Not enough operands!" << endl;
                return -1;
            }
            int a = s.pop();
            int result;

            switch (c) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0) {
                    cout << "Error: Division by zero!" << endl;
                    return -1;
                }
                result = a / b; 
                break;
            }

            s.push(result);
        }
        else {
            cout << "Error: Invalid symbol in postfix expression!" << endl;
            return -1;
        }
    }

    if (s.isEmpty()) {
        cout << "Error: Invalid postfix expression!" << endl;
        return -1;
    }

    int finalResult = s.pop();

    if (!s.isEmpty()) {
        cout << "Error: Too many operands!" << endl;
        return -1;
    }

    return finalResult;
}


int main() {
    string infix;

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    // If error message returned
    if (postfix.rfind("Error", 0) == 0) {
        cout << postfix << endl;
        return 0;
    }

    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
