#include <iostream>

using namespace std;
class Deque
{
private:
    int *arr;
    int front;
    int rear;
    int n;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        this->n=n;
        arr=new int[n];
        front=-1;
        rear=-1;
        // Write your code here.
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull())
        {
            return false;
        }
        //i have to push in front
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            arr[front]=x;
            return true;
        }
        if(front==0)
        {
            front=n-1;
            arr[front]=x;
            return true;
        }
        front=(front-1)%n;
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull())
        {
            return false;
        }
        //i have to push in front
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            arr[front]=x;
            return true;
        }
        rear=(rear+1)%n;
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        if(rear==front)
        {
            int ans=arr[front];
            rear=front=-1;
            return ans;
        }
        int ans=arr[front];
        front=(front+1)%n;
        return ans;

    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty())
        {
            return -1;
        }
        if(rear==front)
        {
            int ans=arr[rear];
            rear=front=-1;
            return ans;
        }
        if(rear==0)
        {
            int ans=arr[rear];
            rear=n-1;
            return ans;
        }
        int ans=arr[rear];
        rear=(rear-1)%n;
        return ans;

    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty())
        {
            return -1;
        }
        return arr[rear];

    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1 && rear==-1)
        {
            return true;
        }
        return false;

    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((rear+1)%n==front)
        {
            return true;
        }
        return false;

    }
};
int main()
{
    int size;
    cout << "Enter size of Deque: ";
    cin >> size;

    Deque dq(size);
    int choice, value;

    do
    {
        cout << "\n--- Deque Menu ---\n";
        cout << "1. Push Front\n";
        cout << "2. Push Rear\n";
        cout << "3. Pop Front\n";
        cout << "4. Pop Rear\n";
        cout << "5. Get Front\n";
        cout << "6. Get Rear\n";
        cout << "7. Check if Empty\n";
        cout << "8. Check if Full\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter value to push at front: ";
            cin >> value;
            if (dq.pushFront(value))
                cout << "Pushed at front.\n";
            else
                cout << "Deque is Full!\n";
            break;
        case 2:
            cout << "Enter value to push at rear: ";
            cin >> value;
            if (dq.pushRear(value))
                cout << "Pushed at rear.\n";
            else
                cout << "Deque is Full!\n";
            break;
        case 3:
            value = dq.popFront();
            if (value == -1)
                cout << "Deque is Empty!\n";
            else
                cout << "Popped from front: " << value << endl;
            break;
        case 4:
            value = dq.popRear();
            if (value == -1)
                cout << "Deque is Empty!\n";
            else
                cout << "Popped from rear: " << value << endl;
            break;
        case 5:
            value = dq.getFront();
            if (value == -1)
                cout << "Deque is Empty!\n";
            else
                cout << "Front element: " << value << endl;
            break;
        case 6:
            value = dq.getRear();
            if (value == -1)
                cout << "Deque is Empty!\n";
            else
                cout << "Rear element: " << value << endl;
            break;
        case 7:
            cout << (dq.isEmpty() ? "Deque is Empty\n" : "Deque is NOT Empty\n");
            break;
        case 8:
            cout << (dq.isFull() ? "Deque is Full\n" : "Deque is NOT Full\n");
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice! Try again.\n";
        }
    }
    while (choice != 9);

    return 0;
}
