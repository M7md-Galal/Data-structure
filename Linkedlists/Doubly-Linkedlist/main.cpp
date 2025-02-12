#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add a node at the end
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Add a node at the beginning
    void prepend(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Delete a node by value
    void deleteByValue(T value) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == value) {
                if (temp->prev) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;  // Moving head if node to delete is head
                }

                if (temp->next) {
                    temp->next->prev = temp->prev;
                } else {
                    tail = temp->prev;  // Moving tail if node to delete is tail
                }

                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found!" << endl;
    }

    // Display the list from the head to the tail
    void displayForward() const {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display the list from the tail to the head
    void displayBackward() const {
        Node<T>* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Destructor to delete the list and free memory
    ~DoublyLinkedList() {
        Node<T>* temp = head;
        while (temp) {
            Node<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    // Create a doubly linked list of integers
    DoublyLinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);

    cout << "Forward display: ";
    list.displayForward();

    cout << "Backward display: ";
    list.displayBackward();

    list.deleteByValue(20);

    cout << "After deletion of 20:" << endl;
    cout << "Forward display: ";
    list.displayForward();

    return 0;
}
