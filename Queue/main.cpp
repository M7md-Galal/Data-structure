#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;       // Pointer to dynamic array for queue storage
    int size;       // Current number of elements in the queue
    int front, rear; // Front and rear indices
    int capacity;   // Maximum capacity of the queue

public:
    // Constructor Initializes queue with given capacity
    Queue(int capacity) : capacity(capacity), front(-1), rear(-1), size(0), arr(new int[capacity]) {}

    // Destructor: Releases allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity - 1;
    }

    // Insert an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            throw overflow_error("Queue is full!");
        }
        else if (isEmpty()) {
            front = rear = 0; // If queue was empty, set both front and rear to 0
        }
        else {
            rear++; // Increment rear to point to the new position
        }

        arr[rear] = value; // Store the value in the queue
        size++;
        cout << "Enqueued: " << value << endl;
    }

    // Remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) { // If there was only one element
            front = rear = -1; // Reset queue
        }
        else {
            front++; // Move front pointer to the next element
        }

        size--;
    }

    // Get the front element without removing it
    int peekFront() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        return arr[front];
    }

    // Get the rear element without removing it
    int peekRear() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty!");
        }
        return arr[rear];
    }

    // Get the current size of the queue
    int Size() {
        return size;
    }

    // Display all elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        for (int j = 0; j < size; j++) {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }
};

int main() {
    Queue q(7); // Create a queue with a capacity of 7

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    // Print the front and rear elements
    cout << q.peekFront() << endl;
    cout << q.peekRear() << endl;

    q.dequeue(); // Remove the front element

    // Print the new front and rear elements
    cout << q.peekFront() << endl;
    cout << q.peekRear() << endl;

    // Display the current queue state
    q.display();

    return 0;
}
