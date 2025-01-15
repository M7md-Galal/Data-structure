#include <iostream>
using namespace std;


template<typename T>
class Node
{
public:
    T Data;
    Node* Next;
};


template<typename T>
class LinkedList
{
public:
    Node<T>* Head;

    // Constructor: initializes an empty linked list
    LinkedList()
    {
        Head = NULL;
    }

    // Check if the list is empty
    bool isEmpty()
    {
        return (Head == NULL);
    }

    // Insert a new item at the front of the list
    void insert_front(T item)
    {
        Node<T>* newNode = new Node<T>;
        newNode->Data = item;

        if (isEmpty())
        {
            Head = newNode;              // Make the new node the head
            newNode->Next = nullptr;     // Set the next pointer to null
        }
        else  // If the list is not empty
        {
            newNode->Next = Head;        // Point the new node to the current head
            Head = newNode;              // Update the head to the new node
        }
    }

    // Display all items in the list
    void Display()
    {
        Node<T>* Temp = Head;  // Start at the head
        while (Temp != nullptr)  // Traverse the list
        {
            cout << Temp->Data << " ";  // Print the data
            Temp = Temp->Next;  // Move to the next node
        }
    }

    // Search for an item in the list
    bool Search(T item)
    {
        Node<T>* Temp = Head;  // Start at the head
        while (Temp != nullptr)  // Traverse the list
        {
            if (Temp->Data == item)  // If the item is found
            {
                return true;
            }
            Temp = Temp->Next;  // Move to the next node
        }
        return false;  // Item not found
    }

    // Insert an item after a specified index
    void insertAt(T index, T value)
    {
        if (isEmpty())  // If the list is empty
        {
            //insert_front(value);
            Node<T>* newNode = new Node<T>;  // Create a new node
            newNode->Data = value;           // Set the data for the new node
            Head = newNode;                  // Make the new node the head
            newNode->Next = nullptr;         // Set the next pointer to null
        }
        else
        {
            Node<T>* Temp = Head;  // Start at the head
            while (Temp->Next != nullptr && Temp->Next->Data != index)  // Traverse to find the index
            {
                Temp = Temp->Next;  // Move to the next node
            }
            Node<T>* newNode = new Node<T>;  // Create a new node
            newNode->Data = value;           // Set the data for the new node
            newNode->Next = Temp->Next;      // Link the new node to the next node
            Temp->Next = newNode;            // Link the previous node to the new node
        }
    }

    // Insert an item at the back of the list
    void insert_back(T value)
    {
        if (isEmpty())  // If the list is empty
        {
            insert_front(value);  // Insert the item at the front (since it's the first item)
        }
        else
        {
            Node<T>* Temp = Head;  // Start at the head
            while (Temp->Next != nullptr)  // Traverse to the end of the list
            {
                Temp = Temp->Next;  // Move to the next node
            }
            Node<T>* newNode = new Node<T>;  // Create a new node
            newNode->Data = value;           // Set the data for the new node
            newNode->Next = nullptr;         // Set the next pointer to null
            Temp->Next = newNode;            // Link the last node to the new node
        }
    }

    // Delete an item from the list
    void Delete_item(T item)
    {
        if (isEmpty())  // If the list is empty
        {
            cout << "The List is Empty\n";
        }
        else if (Head->Data == item)  // If the item is at the head
        {
            Node<T>* Temp = Head;  // Temporarily store the head
            Head = Head->Next;     // Move the head to the next node
            delete Temp;           // Delete the old head
        }
        else
        {
            Node<T>* newNode = Head;  // Start at the head
            Node<T>* Temp = NULL;     // Previous node pointer
            while (newNode->Data != item)  // Traverse to find the item
            {
                Temp = newNode;  // Store the current node
                newNode = newNode->Next;  // Move to the next node
            }
            Temp->Next = newNode->Next;  // Link the previous node to the next node
            delete newNode;  // Delete the node containing the item
        }
    }
};

int main()
{
    LinkedList<int> list;  // Create a linked list of integers

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
