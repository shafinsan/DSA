#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularSinglyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    CircularSinglyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtHead(int data)
    {
        Node* newNode = new Node(data);
        if (head == nullptr)
        {
            head = tail = newNode;
            newNode->next = newNode; // Points to itself
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

    // Insert at the end
    void insertAtTail(int data)
    {
        Node* newNode = new Node(data);
        if (head == nullptr)
        {
            insertAtHead(data);
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    // Delete from the beginning
    void deleteAtHead()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    // Delete from the end
    void deleteAtTail()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail)
        {
            deleteAtHead();
            return;
        }
        Node* current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        Node* temp = tail;
        tail = current;
        tail->next = head;
        delete temp;
    }

    // Insert at a given position (1-based)
    void insertAtPosition(int position, int data)
    {
        if (position <= 1)
        {
            insertAtHead(data);
            return;
        }

        Node* current = head;
        int count = 1;

        while (count < position - 1 && current->next != head)
        {
            current = current->next;
            count++;
        }

        if (current->next == head)
        {
            insertAtTail(data);
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
    }

    // Delete at a given position (1-based)
    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (position <= 1)
        {
            deleteAtHead();
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        int count = 1;

        while (count < position && current->next != head)
        {
            prev = current;
            current = current->next;
            count++;
        }

        if (current->next == head && count < position)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        prev->next = current->next;
        if (current == tail)
        {
            tail = prev;
        }
        delete current;
    }

    // Display the list
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        while (current != head);

        cout << "(head)" << endl;
    }

    // Destructor to free memory
    ~CircularSinglyLinkedList()
    {
        if (head == nullptr) return;

        Node* current = head;
        Node* temp;

        do
        {
            temp = current;
            current = current->next;
            delete temp;
        }
        while (current != head);

        head = tail = nullptr;
    }
};
int main()
{
    CircularSinglyLinkedList csll;

    csll.insertAtHead(10);
    csll.insertAtTail(20);
    csll.insertAtPosition(2, 15);
    csll.display(); // Output: 10 -> 15 -> 20 -> (head)

    csll.deleteAtPosition(2);
    csll.display(); // Output: 10 -> 20 -> (head)

    csll.deleteAtHead();
    csll.display(); // Output: 20 -> (head)

    csll.deleteAtTail();
    csll.display(); // Output: List is empty

    return 0;
    return 0;
}
