#include <iostream>

using namespace std;
class node{
public:
    int data;
    node* next;
    node* pre;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->pre=NULL;
    }
};

void insertAtHead(node* &head,node* &tail,int data){
    node *temp=new node(data);
    temp->next=head;
    head->pre=temp;
    head=temp;

}
void insertAtTail(node* &head,node* &tail,int data){
    node* temp=head;
    node* newNode=new node(data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->pre=temp;
    temp->next=newNode;
    temp=newNode;
    tail=newNode;

}
void insertAtAnyPosition(node* &head,node* &tail,int position,int data){
    if(position<=1){
        insertAtHead(head,tail,data);
        return;
    }
    node *temp=head;
    node *newNode=new node(data);
    node *nextNode=NULL;
    int cnt=1;
    while(cnt<position-1){
        if(temp->next->next==NULL){
            insertAtTail(head,tail,data);
            return;
        }
        temp=temp->next;
        cnt++;
    }
    nextNode=temp->next;
    temp->next=newNode;
    newNode->next=nextNode;
    newNode->pre=temp;
    nextNode->pre=newNode;

}
void deleteAtHead(node* &head){
    node* temp=head;
    head=temp->next;
    head->pre=NULL;
    delete temp;
}
void deleteAtTail(node* &tail){
    node* temp=tail;
    tail=temp->pre;
    tail->next=NULL;
    delete temp;
}
void deleteAtAnyPosition(node* &head,node* &tail,int position){
    if(position<=1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt<position){
        if(temp->next->next==NULL){
            deleteAtTail(tail);
            return;
        }
        temp=temp->next;
        cout<<endl<<"current temp :"<<temp->data<<endl;
        cnt++;
    }
    node *pre=temp->pre;
    node *next=temp->next;
    pre->next=next;
    next->pre=pre;
    delete temp;
}
void display(node* &head,node* &tail){
    node* temp=head;
    node *temp2=tail;
    while(temp!=NULL){
        if(temp->next==NULL){
            cout<<temp->data<<endl;
        }
        else{
            cout<<temp->data<<"->";
        }
        temp=temp->next;
    }
    cout<<"reverse"<<endl;
     while(temp2!=NULL){
        if(temp2->pre==NULL){
            cout<<temp2->data<<endl;
        }
        else{
            cout<<temp2->data<<"->";
        }
        temp2=temp2->pre;
    }

}

int main() {
    node* head = nullptr;
    node* tail = nullptr;
    int choice, data, position;

    do {
        cout << "\n====== Doubly Linked List Menu ======\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Any Position\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Delete at Any Position\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> data;
                if (head == nullptr) {
                    head = tail = new node(data);
                } else {
                    insertAtHead(head, tail, data);
                }
                break;

            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> data;
                if (head == nullptr) {
                    head = tail = new node(data);
                } else {
                    insertAtTail(head, tail, data);
                }
                break;

            case 3:
                cout << "Enter position and value to insert: ";
                cin >> position >> data;
                if (head == nullptr) {
                    head = tail = new node(data);
                } else {
                    insertAtAnyPosition(head, tail, position, data);
                }
                break;

            case 4:
                if (head == nullptr) {
                    cout << "List is empty.\n";
                } else {
                    deleteAtHead(head);
                }
                break;

            case 5:
                if (tail == nullptr) {
                    cout << "List is empty.\n";
                } else {
                    deleteAtTail(tail);
                }
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                if (head == nullptr) {
                    cout << "List is empty.\n";
                } else {
                    deleteAtAnyPosition(head, tail, position);
                }
                break;

            case 7:
                if (head == nullptr) {
                    cout << "List is empty.\n";
                } else {
                    display(head, tail);
                }
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
