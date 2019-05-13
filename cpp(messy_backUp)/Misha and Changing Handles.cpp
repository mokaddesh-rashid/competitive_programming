#include<iostream>

using namespace std;

int x=0;


class node
{
public:
    string old,neww;
    node *next;

};

node *root=NULL;

void kanp(string str,string st)
{
    node *newnode=new node;
    newnode->old=str;
    newnode->neww=st;
    newnode->next=NULL;

    if(root==NULL)
    {
        root=newnode;
        x++;
    }

    else
    {
        node *t=root;

        while(t->next!=NULL&&t->neww!=newnode->old)
        {
            t=t->next;
        }

        if(t->neww==newnode->old)
        {
            t->neww=newnode->neww;
        }

        else
        {
            x++;
            t->next=newnode;
        }

    }
}

void display()
{
       node *t=root;

        while(t->next!=NULL)
        {
            cout<<t->old<<' '<<t->neww<<endl;
            t=t->next;
        }

         cout<<t->old<<' '<<t->neww<<endl;
}

int main()
{
   int n,i;


   cin>>n;

   string old,neww;


   for(i=0;i<n;i++)
   {
       cin>>old>>neww;

       kanp(old,neww);

   }
   cout<<x<<endl;
   display();
}
