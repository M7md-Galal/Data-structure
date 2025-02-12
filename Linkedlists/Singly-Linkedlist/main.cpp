#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T Data;
    Node* Next;
};

template<typename T>
class Linkedlist {
public:
    Node<T>* Head;

    Linkedlist() {
        Head = NULL;
    }

    // Check if the list is empty
    bool isEmpty() {
        return Head == NULL;
    }

    // Insert a new node at the front of the list
    void insert_front(T item) {
        Node<T>* newNode = new Node<T>;
        newNode->Data = item;
        if (isEmpty()) {
            newNode->Next = nullptr;
            Head = newNode;
        } else {
            newNode->Next = Head;
            Head = newNode;
        }
    }

    // Insert a new node after the node containing the specified item
    void insertAt(T index, T item) {
        if (isEmpty()) {
            insert_front(item);
        } else {
            Node<T>* Temp = Head;
            while (Temp->Next != nullptr && Temp->Next->Data != index) {
                Temp = Temp->Next;
            }
            Node<T>* newNode = new Node<T>;
            newNode->Data = item;
            newNode->Next = Temp->Next;
            Temp->Next = newNode;
        }
    }

    // Insert a new node at the back of the list
    void insert_back(T item) {
        if (isEmpty()) {
            insert_front(item);
        } else {
            Node<T>* Temp = Head;
            // Fixed the loop condition to find the last node
            while (Temp->Next != nullptr) {
                Temp = Temp->Next;
            }
            Node<T>* newNode = new Node<T>;
            newNode->Data = item;
            newNode->Next = nullptr;
            Temp->Next = newNode;
        }
    }

    // Delete the first occurrence of the item from the list
    void Delete_item(T item) {
        if (isEmpty()) {
            cout << "The list is empty!\n";
        } else if (Head->Data == item) {
            Node<T>* Temp = Head;
            Head = Head->Next;
            delete Temp;
        } else {
            Node<T>* delNode = Head;
            Node<T>* Temp = nullptr;
            while (delNode->Data != item) {
                Temp = delNode;
                delNode = delNode->Next;
            }
            Temp->Next = delNode->Next;
            delete delNode;
        }
    }

    // Display all elements in the list
    void Display() {
        Node<T>* Temp = Head;
        cout << "Display: ";
        while (Temp != nullptr) {  // Fixed to display the last node
            cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
        cout << endl;
    }

    // Search for an item in the list
    bool Search(T item) {
        Node<T>* Temp = Head;
        while (Temp != nullptr) {  // Fixed the loop condition to check all nodes
            if (Temp->Data == item) {
                return true;  // Item found
            }
            Temp = Temp->Next;
        }
        return false;  // Item not found
    }
};

int main() {
    Linkedlist<int> list;  // Create a linked list of integers

    // Insert items at the front of the list
    list.insert_front(50);
    list.insert_front(40);
    list.insert_front(30);
    list.insert_front(20);
    list.insert_front(10);
    cout << "Items inserted at the front: ";
    list.Display();  // Display the list after inserting items at the front
    cout << endl;

    // Search for an item in the list
    if (list.Search(30)) {
        cout << "\nThe Number is Found\n";
    } else {
        cout << "\nThe Number is Not Found\n";
    }

    // Insert an item after a specified index
    list.insertAt(40, 90);
    cout << "Items after inserting at specified position: ";
    list.Display();  // Display the list after inserting
    cout << endl;

    // Insert an item at the back of the list
    list.insert_back(100);
    cout << "Items after inserting at the back: ";
    list.Display();  // Display the list after inserting at the back
    cout << endl;

    // Delete an item from the list
    list.Delete_item(30);
    cout << "Items after deletion: ";
    list.Display();  // Display the list after deletion
    cout << endl;

    return 0;
}
