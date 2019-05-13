#include<iostream>

using namespace std;

class node
{
public:
    int value;
    node *next;
};
node *root=NULL;
void enque(int x)
{
    node *newnode=new node;
    newnode->value=x;
    newnode->next=NULL;

    if(root==NULL) root=newnode;
    else
    {
        node *t=root;
        if(t->value<x)
        {
            newnode->next=root;
            root=newnode;
        }
        else
        {
            while(t->next!=NULL&&t->next->value>x)
            {
                t=t->next;
            }
        if(t->next==NULL)
        {
            t->next=newnode;
        }
        else
        {
            newnode->next=t->next;
            t->next=newnode;
        }
        }
    }
}

void display()
{
    node *t=root;

     cout<<"current list\n";
    while(t->next!=NULL)
    {
        cout<<t->value<<' ';
        t=t->next;
    }
     cout<<t->value<<' ';
    cout<<endl;
}


int main()
{
    int i,x,n;

    cout<<"size of the input\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        enque(x);
    }
    display();
}
