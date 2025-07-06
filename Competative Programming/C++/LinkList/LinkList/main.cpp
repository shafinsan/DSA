#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(node* &head,int value)
{
    node* temp=new node(value);
    temp->next=head;
    head=temp;

}
void insertAtTail(node* &head,int value)
{

    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *newNode=new node(value);
    temp->next=newNode;
}
void insertAtPosition(node* &head,int position,int data)
{
    if(position<=1)
    {
        insertAtHead(head,data);
        return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        if(temp->next==NULL)
        {
            break;
        }
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(head,data);
        return;
    }
    node* nextNode=temp->next;
    node* newNode=new node(data);
    temp->next=newNode;
    newNode->next=nextNode;

}

void display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            cout<<temp->data;
        }
        else
        {
            cout<<temp->data<<"->";
        }

        temp=temp->next;
    }
}
//delete at first
void deleteAtHead(node* &head)
{
    node* temp=head;
    head=temp->next;
    delete temp;
}
//delete at last
void deleteAtTail(node* &head)
{
    node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* deleteNode=temp->next;
    temp->next=NULL;
    delete deleteNode;
}
//delete at any position

void deletePosition(node* &head,int position)
{
    node* temp=head;
    if(position<=1)
    {
        deleteAtHead(head);
        return;
    }
    int cnt=1;
    node* pre=NULL;
    node* curr=head;
    while(cnt<position){
        if(curr->next==NULL){
            deleteAtTail(head);
            return;
        }
        pre=curr;
        curr=curr->next;
        cnt++;
    }
    pre->next=curr->next;
    curr->next=NULL;
    delete curr;
}


int main()
{
    node* node1=new node(30);
    node* head=node1;
    insertAtHead(head,20);
    insertAtHead(head,10);
    display(head);
    cout<<endl;
    insertAtTail(head,40);
    display(head);
    cout<<endl;
    insertAtPosition(head,5,500);
    display(head);
    cout<<endl;

    deleteAtHead(head);
    display(head);
    cout<<endl;

    deleteAtTail(head);
    display(head);
    cout<<endl;




    deletePosition(head,2);
    display(head);
    cout<<endl;

}
