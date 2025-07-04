#include <iostream>

using namespace std;
class MyQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    MyQueue(int size)
    {
        this->size=size;
        front=rear=-1;
        arr=new int[size];
    }
    void push(int value)
    {
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            arr[front]=value;
            return;
        }
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else
        {
            rear=(rear+1)%size;
            arr[rear]=value;
            return;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        if(rear==front){
            rear=front=-1;
            return;
        }
        front=(front+1)%size;
    }
    int top()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        int ans=arr[front];
        return ans;
    }
    int first()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[rear];
    }
    bool isFull()
    {
        if(front==-1){
            return false;
        }
        return (rear+1)%size==front?true:false;
    }
    bool isEmpty()
    {
        return (front==-1 && rear==-1)?true:false;
    }
    void display()
    {
        if(rear==-1 && front==-1)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        if(front<=rear)
        {
            for(int i=front; i<=rear; i++)
            {
                cout<<"Queue :"<<arr[i]<<endl;
            }
        }
        else
        {
            for(int i=front; i<size; i++)
            {
                cout<<"Queue :"<<arr[i]<<endl;
            }
            for(int i=0; i<=rear; i++)
            {
                cout<<"Queue :"<<arr[i]<<endl;
            }
        }

    }
};
int main()
{
   int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    MyQueue q(size);
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Front (Top)\n";
        cout << "4. Rear (First)\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            q.push(value);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            cout << "Front Element: " << q.top() << endl;
            break;
        case 4:
            cout << "Rear Element: " << q.first() << endl;
            break;
        case 5:
            q.display();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
