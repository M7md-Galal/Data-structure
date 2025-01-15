#include <iostream>
#include <stack>
using namespace std;
class Stack {
private:
    int* stack;
    int capacity;
    int top;
public:
    // Constructor to initialize the stack
    Stack(int size) : capacity(size), top(-1), stack(new int[capacity]) {}
    Stack() {};
    ~Stack() { delete[] stack; }
    // check if the stack is empty
    bool IsEmpty() const { return top == -1; }
    // check if the stack is full
    bool IsFull() const { return top == capacity - 1; }
    // add an element to the stack
    void Push(int value) {
        if (!IsFull()) {
            stack[++top] = value; // Increment top and add the value
            return;
        }

        throw overflow_error("Stack Overflow: Cannot push element.");
    }
    // remove the top element from the stack
    void PoP() {
        if (!IsEmpty()) {
            --top; // Decrement the top index
            return;
        }
        throw underflow_error("Stack Underflow: Cannot pop element.");
    }
    // display all elements in the stack
    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack s1(10);  // Create stack object with capacity of 10
    // Push elements into the stack
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(5);
    s1.Display();
    // Pop three elements from the stack
    s1.PoP();
    s1.PoP();
    s1.PoP();
    // Display the remaining elements in the stack
    s1.Display();
    return 0;
}