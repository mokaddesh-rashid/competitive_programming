#include<iostream>

using namespace std;


class node
{
    public:
    int data;
    node *next, *prev;
};

node *root=NULL, *last=NULL;

void addlast(int value)
{
    node *newnode=new node;

    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(root==NULL) root=newnode;
    else
    {
        node *t=root;

        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=newnode;
        newnode->prev=t;
        last=newnode;
    }
}

void delete_between(int x,int y)
{
    node *t=root;

    while(t->next->next!=NULL)
    {
        if(t->data==x&&t->next->next->data==y)
        {
          t->next=t->next->next;
          t->next->prev=t;
          cout<<"deleted\n";
          return;
        }
        t=t->next;
    }
    cout<<"Can`t find such case\n"<<endl;
    cout<<endl;
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

void display_rev()
{
    cout<<"current list in reverse : ";
    node *t=last;

    while(t!=NULL)
    {
        cout<<t->data<<' ';
        t=t->prev;
    }
    cout<<endl;

}
int main()
{
  addlast(1);
  addlast(2);
  addlast(3);
  addlast(4);
  addlast(5);
  display_rev();
  display();
  delete_between(2,4);
  display_rev();
  display();
  delete_between(2,4);


}


