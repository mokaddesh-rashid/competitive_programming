#include<iostream>

using namespace std;


class node
{
    public:
    int data;
    node *next;
};

node *root=NULL;

void addlast(int value)
{
    node *newnode=new node;

    newnode->data=value;
    newnode->next=NULL;

    if(root==NULL)
    {
        root=newnode;
    }

    else
    {
        node *t=root;

        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=newnode;
    }
}

void addfirst(int value)
{
    node *newnode=new node;

    newnode->data=value;
    newnode->next=NULL;

    if(root==NULL)
    {
        root=newnode;
    }

    else
    {
        newnode->next=root;
        root=newnode;
    }
}
void display()
{
    cout<<"current list : ";
    node *t=root;

    while(t->next!=NULL)
    {
        cout<<t->data<<' ';
        t=t->next;
    }
     cout<<t->data<<' ';
    cout<<endl;

}
int main()
{
  addlast(1);
  display();
  addfirst(2);
  display();
  addlast(3);
  display();
  addfirst(4);
  display();
  addlast(5);
  display();
  addfirst(6);
  display();

}
