
#include<iostream>
#include<string>

using namespace std;

class node
{
public:
    string value;
    int time;
    node *next;
    node *prev;

};

node *root=NULL;
node *end0=NULL;

int sorted(string x)
{
    node *newnode=new node;

    newnode->value=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->time=0;

    if(root==NULL)
    {
        root=newnode;
        end0=newnode;
    }
    else if(root->value>=x)
    {

        newnode->next=root;
        root->prev=newnode;
        root=newnode;
    }
    else if(end0->value<=newnode->value)
    {
        newnode->prev=end0;
        end0->next=newnode;
        end0=newnode;
    }
    else
    {
        node *t=root;
        node *s=end0;

        while(t->next->value<=x&&s->prev->value>=x)
        {
            t=t->next;
            s=s->prev;
        }



       if(t->next->value>x)
        {
             newnode->prev=t;
             newnode->next=t->next;
             t->next->prev=newnode;
             t->next=newnode;
        }
        else if(s->prev->value<x)
        {
             newnode->next=s;
             newnode->prev=s->prev;
             s->prev->next=newnode;
             s->prev=newnode;
        }

    }


}

void display()
{
    node *t=root;
    node *s=end0;

    cout<<"current list ";
    while(t->next!=NULL)
    {
        cout<<t->value<<' ';
        t=t->next;
    }
    cout<<t->value<<' '<<endl<<endl;


    while(s->prev!=NULL)
    {
        cout<<s->value<<' ';
        s=s->prev;
    }
    cout<<s->value<<' '<<endl<<endl;




}

int main()
{
    string a;
    int i;
    for(i=0;i>=0;i++)
    {
        cin>>a;
        sorted(a);
        display();
    }
}
