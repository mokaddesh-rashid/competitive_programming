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

    if(root==NULL) root=newnode;
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

void display()
{
    cout<<"current list : ";
    node *t=root;

    while(t!=NULL)
    {
        cout<<t->data<<' ';
        t=t->next;
    }
    cout<<endl;

}
int main()
{
  addlast(10);
  addlast(2);
  addlast(3);
  addlast(4);
  addlast(5);
  display();
}

