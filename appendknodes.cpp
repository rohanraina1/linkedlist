#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next= NULL;
    }
};
void insert(node* & head, int v)
{
    node* temp= head;
    node* n = new node(v);
    if(head==NULL)
    {
        head= n ;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next= n ;
}
void display(node* head)
{
    node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp= temp->next;
    }
}
int length(node* head)
{
    int l=0;
    node* temp = head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}
node* appendknodes(node* & head, int k)
{
    node* newhead;
    node* newtail;
    node* tail= head;
    int l = length(head);
    int count =1 ;
    while(tail->next!= NULL)
    {
        if(count==l-k)
        {
            newtail= tail;
        }
        if(count==l-k+1)
        {
            newhead=tail;
        }
        tail=tail->next;
        count++;
    
    }
    newtail->next=NULL;
    tail->next=head;   
     return newhead;
}
int main()
{
    node* head= NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0 ; i<6 ; i++)
    {
        insert(head,arr[i]);
    }
    node * newhead = appendknodes(head,4);
    display(newhead);
}