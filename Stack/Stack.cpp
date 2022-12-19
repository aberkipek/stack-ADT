#include <iostream>
#include "Stack.h"

using std::cout;
using std::endl;

int Stack::index = -1, Stack::stackSize = 0;

void Stack::push(string operation) {
    if (isFull())
        cout << "Stack overflow!" << endl;
    else {
        index++;
        stack[index] = operation;
        stackSize++;
    }
}

void Stack::pop() {
    if (isEmpty())
        cout << "Stack is already empty!" << endl;
    else {
        stack[index] = " ";
        stackSize--;
        index--;
    }
}

int Stack::size() {
    return stackSize;
}

string Stack::peek() {
    if (!isEmpty()) 
        return stack[index];
    else 
        return "Stack is empty!";
}

bool Stack::isFull() {
    if (stackSize == sizeof(stack) / sizeof(string))
        return 1;
    else
        return 0;
}

bool Stack::isEmpty() {
    if (stackSize == 0)
        return 1;
    else
        return 0;
}

void Stack::printStackElements() {
    if (!isEmpty()) {
        cout << "Stack elements: ";
        for (int i = 0; i < stackSize; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Stack is empty!" << endl;
}

int main() {
    Stack s;
    cout << "Last element of the stack: " << s.peek() << endl; // Stack is empty!
    s.push("+");
    s.push("-");
    s.push("/");
    s.printStackElements();
    s.push("*");
    s.push("-");
    s.printStackElements(); // Stack is full!
    s.push("+"); // Stack overflow!
    s.pop();
    s.pop();
    s.printStackElements();
    s.pop();
    cout << "Size: " << s.size() << endl;
    s.pop();
    s.pop(); // Stack is empty!
    s.pop(); // Stack is already empty!
    s.printStackElements();
    return 0;
}