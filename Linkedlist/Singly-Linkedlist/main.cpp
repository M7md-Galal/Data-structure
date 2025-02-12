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
    bool isEmpty() {
        return Head == NULL;
    }
    void insert_front(T item) {
        Node<T>* newNode = new Node<T>;
        newNode->Data = item;
        if(isEmpty()) {
            newNode->Next = nullptr;
            Head = newNode;
        }
        else {
            newNode->Next = Head;
            Head = newNode;
        }
    }
    void insertAt(T index, T item) {
        if(isEmpty()) {
            insert_front(item);
        }
        else {
            Node<T>* Temp = Head;
            while(Temp->Next!= nullptr&&Temp->Next->Data!= index) {
                Temp = Temp->Next;
            }
            Node<T>* newNode = new Node<T>;
            newNode->Data = item;
            newNode->Next = Temp->Next;
            Temp->Next = newNode;
        }
    }
    void insert_back(T item) {
        if(isEmpty()) {
            insert_front(item);
        }
        else {
            Node<T>* Temp = Head;
            while(Temp != nullptr) {
                Temp = Temp->Next;
            }
            Node<T>* newNode = new Node<T>;
            newNode->Data = item;
            newNode->Next = nullptr;
            Temp->Next = newNode;

        }
    }
    void Delete_item(T item) {
        if(isEmpty()) {
            cout<<"the list is Empty!\n";
        }
        else if(Head->Data == item) {
            Node<T>* Temp = Head;
            Head = Head->Next;
            delete Temp;
        }
        else {
            Node<T>* delNode = Head;
            Node<T>* Temp = NULL;
            while(delNode->Data!= item) {
                Temp = delNode;
                delNode = delNode->Next;
            }
            Temp->Next = delNode->Next;
            delete delNode;
        }
    }
    void Display() {
        Node<T>* Temp = Head;
        cout<<"Display: ";
        while(Temp->Next!= nullptr) {
            cout<<Temp->Data<<" ";
            Temp = Temp->Next;
        }
    }
    bool Search(T item) {
        Node<T>* Temp = Head;
        while(Temp->Data != item) {
            if(Temp->Data == item) {
                return true;
            }
            Temp = Temp->Next;
        }
        return false;
    }
};


int main()
{
    Linkedlist<int> list;  // Create a linked list of integers

#pragma region Insert Front
    list.insert_front(50);
    list.insert_front(40);
    list.insert_front(30);
    list.insert_front(20);
    list.insert_front(10);
    cout << "items inserted front: ";
    list.Display();  // Display the list after inserting items at the front
    cout << endl;

    /*
    // Optional: insert multiple numbers by user input
    int n;
    cout << "How Many Number You Want to insert: \n";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        short num;
        cout << "Enter The inserted: \n";
        cin >> num;
        list.insert_front(num);
    }
    list.Display();
    cout << endl;
    */
#pragma endregion

    // Search for an item in the list
    if (list.Search(30))
    {
        cout << "\nThe Number is Found\n";
    }
    else
    {
        cout << "\nThe Number is  Not Found\n";
    }

    // Insert an item after a specified index
    list.insertAt(40, 90);
    cout << "items inserted At: ";
    list.Display();  // Display the list after inserting
    cout << endl;

    // Insert an item at the back of the list
    list.insert_back(100);
    cout << "items inserted back: ";
    list.Display();  // Display the list after inserting
    cout << endl;

    // Delete an item from the list
    list.Delete_item(30);
    cout << "items after deleted: ";
    list.Display();  // Display the list after deletion
    cout << endl;

    return 0;
}