#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insert(node*&head,int value)
{
    node* n = new node(value);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp= head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void display(node*head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
void deleteathead(node*&head)
{
    node* temp= head;
    head=head->next;
    delete temp;
}
void deletetion(node* &head,int v)
{
    if(head==NULL)
    {
        return ;
    }
    if(head->next==NULL)
    {
        deleteathead(head);
    }
    node* temp=head;
    while(temp->next->data!=v)
    {
        temp=temp->next;

    }
    node * todelete= temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
int main()
{
    node * head= NULL;
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insert(head,8);
    insert(head,9);
    deletetion(head,8);
    deleteathead(head);
    display(head);
}