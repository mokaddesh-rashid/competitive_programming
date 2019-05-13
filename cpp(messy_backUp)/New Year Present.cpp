#include<iostream>

using namespace std;

class node
{
public:
    int value;
    node *next;
    node *prev;
};

node *root=NULL;
node *end0=NULL;

void enque(int x)
{
    node *newnode=new node;

    newnode->value=x;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(root==NULL)
    {
        root=newnode;
        end0=newnode;
    }
    else
    {
        end0->next=newnode;
        newnode->prev=end0;
        end0=newnode;
    }
}

void check()
{
    node *t=root;

    while(t->next!=NULL)
    {
        if(t->value<=0)
           {
                t=t->next;
                cout<<'R';
           }
        else if(t->value>0)
        {
            cout<<'P';

            t->value--;

            if(t!=end0)
               {
                    cout<<'R';
                   if(t->next->value>0)
                   {
                       cout<<'P';
                       t->next->value--;
                       cout<<'L';
                   }
                  else
                    cout<<'L';
               }

        }
    }

      t=end0;
    while(t->value>0)
    {
        if(t->value==1)
        {
            cout<<'P';
            t->value--;
        }
        else if(t->value>1)
        {
            cout<<"PLR";
             t->value--;
        }
    }
}

int main()
{
  int n,i;

  cin>>n;

  for(i=0;i<n;i++)
  {
      int a;
      cin>>a;
      enque(a);
  }

  check();
}
