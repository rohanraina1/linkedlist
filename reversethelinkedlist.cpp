#include<iostream>
using namespace std;
class  node{
    public:
int data;
node* next;
node(int val)
{
    data=val;
    next=NULL;
}
  
};
void insertathead(node* &head, int v)
{
    node* m = new node(v);
    m->next=head;
    head=m;

}
void insert(node* &head,int value)
{

     node* n = new node(value);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
         temp=temp->next;
    }
    temp->next=n;

}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
node* reverse(node* &head)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL)
    {
        //This is a iterative way.
        // it is a 3 pointer approach
        nextptr= currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
node* reverserec(node*&head)
{
    //recurrsive way to reverse the linked list .
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //this recurrsive call will reverse all the nodes except the second last node we have to change the link of that node .
    node* newhead = reverserec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
int main()
{
    node* head=NULL;
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insertathead(head,4);
    display(head);
    node* newhead= reverserec(head);
    display(newhead);
    

    return 0;
}
