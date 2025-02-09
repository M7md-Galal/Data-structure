#include <iostream>
using namespace std;

class Stack {
private:
	int* stack;
	int capacity;
	int top;

public:
	Stack(int size) : capacity(size), top(-1), stack(new int[capacity]) {}

	~Stack() { delete[] stack; }

	bool IsEmpty() const { return top == -1; }
	bool IsFull() const { return top == capacity - 1; }

	void Push(int value) {
		if (!IsFull()) {
			stack[++top] = value;
			return;
		}
		throw overflow_error("Stack Overflow: Cannot push element.");
	}

	void Pop() {
		if (!IsEmpty()) {
			top--;
			return;
		}
		throw underflow_error("Stack Underflow: Cannot pop element.");
	}

	void Display() {
		if (IsEmpty()) {
			cout << "Stack is empty" << endl;
			return;
		}
		cout << "Stack elements: ";
		for (int i = 0; i <= top; i++) {
			cout << stack[i];
			if (i < top) cout << ", ";
		}
		cout << endl;
	}

	int Search(int value) {
		for (int i = top; i >= 0; i--) {
			if (stack[i] == value) {
				return top - i + 1; // (based 1 index)
			}
		}
		return -1;
	}
};

int main() {
	Stack s1(10);
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	// s1.Display();
	// s1.Pop();
	// s1.Pop();
	// s1.Pop();
	// s1.Pop();
	// s1.Pop();
	// s1.Display();
    int num = 2;
	int pos = s1.Search(num);
	if (pos != -1)
		cout << "Number is Found\n";
	else
		cout << "Number Not Found\n";

	return 0;
}
