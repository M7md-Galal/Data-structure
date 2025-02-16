#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T Data;
    Node* Next;
    Node* Prev;
};

template<typename T>
class DoublyLinkedList {
public:
    Node<T>* Head;

    DoublyLinkedList() {
        Head = nullptr;
    }

    // Check if the list is empty
    bool isEmpty() {
        return Head == nullptr;
    }

    // Insert a new node at the front of the list
    void insert_front(T item) {
        Node<T>* newNode = new Node<T>;
        newNode->Data = item;
        newNode->Prev = nullptr;
        newNode->Next = Head;

        if (Head != nullptr) {
            Head->Prev = newNode;
        }

        Head = newNode;
    }

    // Insert a new node at the back of the list
    void insert_back(T item) {
        Node<T>* newNode = new Node<T>;
        newNode->Data = item;
        newNode->Next = nullptr;

        if (isEmpty()) {
            newNode->Prev = nullptr;
            Head = newNode;
        } else {
            Node<T>* Temp = Head;
            while (Temp->Next != nullptr) {
                Temp = Temp->Next;
            }
            Temp->Next = newNode;
            newNode->Prev = Temp;
        }
    }

    // Insert after a specific item
    void insert_after(T index, T item) {
        Node<T>* Temp = Head;
        while (Temp != nullptr && Temp->Data != index) {
            Temp = Temp->Next;
        }

        if (Temp != nullptr) {
            Node<T>* newNode = new Node<T>;
            newNode->Data = item;
            newNode->Next = Temp->Next;
            newNode->Prev = Temp;

            if (Temp->Next != nullptr) {
                Temp->Next->Prev = newNode;
            }
            Temp->Next = newNode;
        } else {
            cout << "Item not found!" << endl;
        }
    }

    // Delete an item from the list
    void Delete_item(T item) {
        if (isEmpty()) {
            cout << "The list is empty!" << endl;
            return;
        }

        Node<T>* Temp = Head;
        while (Temp != nullptr && Temp->Data != item) {
            Temp = Temp->Next;
        }

        if (Temp != nullptr) {
            if (Temp == Head) {
                Head = Temp->Next;
                if (Head != nullptr) {
                    Head->Prev = nullptr;
                }
            } else {
                Temp->Prev->Next = Temp->Next;
                if (Temp->Next != nullptr) {
                    Temp->Next->Prev = Temp->Prev;
                }
            }
            delete Temp;
        } else {
            cout << "Item not found!" << endl;
        }
    }

    // Display all items in the list from head to tail
    void Display() {
        Node<T>* Temp = Head;
        cout << "List: ";
        while (Temp != nullptr) {
            cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
        cout << endl;
    }

    // Display all items in the list from tail to head (reverse order)
    void Display_reverse() {
        if (isEmpty()) {
            cout << "The list is empty!" << endl;
            return;
        }

        Node<T>* Temp = Head;
        while (Temp->Next != nullptr) {
            Temp = Temp->Next;
        }

        cout << "List (reverse): ";
        while (Temp != nullptr) {
            cout << Temp->Data << " ";
            Temp = Temp->Prev;
        }
        cout << endl;
    }

    // Search for an item in the list
    bool Search(T item) {
        Node<T>* Temp = Head;
        while (Temp != nullptr) {
            if (Temp->Data == item) {
                return true;
            }
            Temp = Temp->Next;
        }
        return false;
    }
};

int main() {
    DoublyLinkedList<int> list;  // Create a doubly linked list of integers

    // Insert items at the front
    list.insert_front(50);
    list.insert_front(40);
    list.insert_front(30);
    list.insert_front(20);
    list.insert_front(10);

    cout << "Items inserted at the front: ";
    list.Display();  // Display the list after inserting at the front
    cout << endl;

    // Insert items at the back
    list.insert_back(60);
    list.insert_back(70);

    cout << "Items inserted at the back: ";
    list.Display();  // Display the list after inserting at the back
    cout << endl;

    // Insert an item after a specific item (e.g., after 40)
    list.insert_after(40, 45);
    cout << "Items after inserting 45 after 40: ";
    list.Display();  // Display the list after insertion
    cout << endl;

    // Delete an item
    list.Delete_item(30);
    cout << "Items after deleting 30: ";
    list.Display();  // Display the list after deletion
    cout << endl;

    // Display the list in reverse order
    list.Display_reverse();  // Display the list in reverse order

    // Search for an item in the list
    if (list.Search(45)) {
        cout << "\nThe number 45 is found in the list!" << endl;
    } else {
        cout << "\nThe number 45 is not found in the list!" << endl;
    }

    return 0;
}
