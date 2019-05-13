#include<iostream>

using namespace std;

int sell=0;


class node
{

public:
    int v,q;
    node *next,*prev;

};

node *b_root=NULL;
node *b_endd=NULL;

node *s_root=NULL;
node *s_endd=NULL;



void b_add(int x,int y)
{
    node *newnode =new node;

    newnode->v=x;
    newnode->q=y;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(b_root==NULL)
    {
        b_root=newnode;

    }
    else if(b_root->v==x)
    {
        b_root->q+=y;
    }
     else if(b_root->v<x)
    {
       newnode->next=b_root;
       b_root->prev=newnode;
       b_root=newnode;


    }

     else
    {
       node *t=b_root;

       while(t->v>x&&t->next!=NULL)
       {
           t=t->next;
       }

       if(t->v==x)
       {
           t->q+=y;
       }

       else if(t->v<x)
       {
           newnode->next=t;
           newnode->prev=t->prev;

           newnode->next->prev=newnode;
           newnode->prev->next=newnode;


       }

       else
       {
          t->next=newnode;
          newnode->prev=t;

       }
    }


}

void s_add(int x,int y)
{
    node *newnode =new node;

    newnode->v=x;
    newnode->q=y;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(s_root==NULL)
    {
        s_root=newnode;
        sell++;
    }
    else if(s_root->v==x)
    {
        s_root->q+=y;
    }
     else if(s_root->v<x)
    {
       newnode->next=s_root;
       s_root->prev=newnode;
       s_root=newnode;
       sell++;

    }

     else
    {
       node *t=s_root;

       while(t->v>x&&t->next!=NULL)
       {
           t=t->next;
       }

       if(t->v==x)
       {
           t->q+=y;
       }

       else if(t->v<x)
       {
           newnode->next=t;
           newnode->prev=t->prev;

           newnode->next->prev=newnode;
           newnode->prev->next=newnode;

           sell++;
       }

       else
       {
          t->next=newnode;
          newnode->prev=t;
          sell++;
       }
    }


}

void s_display(int s)
{
    node *t=s_root;

    while(t->next!=NULL&&s>0)
    {



        if(sell<=s)
        {
        cout<<'S'<<' '<<t->v<<' '<<t->q<<endl;

        s--;
        }

        t=t->next;
        sell--;
    }

    if(s>0)
      cout<<'S'<<' '<<t->v<<' '<<t->q<<endl;
}

void b_display(int s)
{
    node *t=b_root;

    while(t->next!=NULL&&s>0)
    {

        cout<<'B'<<' '<<t->v<<' '<<t->q<<endl;
        t=t->next;
        s--;
    }

   if(s>0)
    cout<<'B'<<' '<<t->v<<' '<<t->q<<endl;
}

int main()
{
    int n,s,x,y;

    cin>>n>>s;

    for(int i=0 ;i<n;i++)
    {
        char ch;

        cin>>ch;


        if(ch=='B')
        {
            cin>>x>>y;
            b_add(x,y);
        }
        else
        {

            cin>>x>>y;
            s_add(x,y);

        }
    }

    cout<<sell<<endl;
    if(s_root!=NULL)
    s_display(s);

    if(b_root!=NULL)
    b_display(s);
}
