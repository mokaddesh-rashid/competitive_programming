#include<iostream>

using namespace std;

int n,x,res=0;

class node
{
public:
    int start,finish;
    node *next;

};

node *root=NULL;
node *end0=NULL;

void enque()
{
    node *newnode=new node;

    cin>>newnode->start;
    cin>>newnode->finish;

    while((newnode->start-1)%x!=0)
    {
        newnode->start--;
    }
    newnode->next=NULL;

    if(root==NULL)
    {
        root=newnode;
        end0=newnode;
    }

    else
    {
       end0->next=newnode;
       end0=newnode;

    }
};

void display()
{
    node *t=root;

    while(t->next!=NULL)
    {
        cout<<t->first<<' ';
        t=t->next;
    }
      cout<<t->first<<' '<<endl;
}

void check()
{
    node *t=root;

    while(t->next!=NULL)
    {
        res=res+(t->finish-t->start)+1;
        t=t->next;
    }
     res=res+(t->finish-t->start)+1;
}

int main()
{
    cin>>n>>x;

    for(int i=0;i<n;i++)
    {

        enque();
    }
    display()
    check();
    cout<<res;
}
