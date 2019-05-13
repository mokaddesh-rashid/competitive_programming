#include<iostream>

using namespace std;

class node
{
public:
    int val;
    node *next;
};

node *root=NULL;
node *last=NULL;
node *newroot=NULL;

void add_last(int x)
{
    node *newnode=new node;

    newnode->val=x;
    newnode->next=NULL;

    if(root==NULL)
    {
        root=newnode;
        last=newnode;
    }

    else
    {
        last->next=newnode;
        last=newnode;
    }
}

void reverse_it()
{
    node *t=root->next;
    node *s=t->next;
    while(root->next!=NULL)
    {
        if(newroot==NULL)
        {
           root->next=t->next;
           t->next=root;
           newroot=t;
           t=root->next;
           //s=s->next;

        }

        else
        {
            root->next=t->next;
            t->next=newroot;
            newroot=t;
             t=root->next;
           // s=s->next;
        }
    }
}

void display()
{
    node *t=newroot;

    while(newroot->next!=NULL)
    {
        cout<<t->val<<' ';
        t=t->next;
    }

     cout<<t->val<<endl;
}

int main()
{
    add_last(1);
     add_last(2);
      add_last(3);
       add_last(4);
        add_last(5);
     add_last(6);
      add_last(7);
       add_last(8);
        add_last(9);
    reverse_it();
    display();
    return 0;
}
