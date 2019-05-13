#include<iostream>

using namespace std;

class node
{
public:
    int x,t;
    node *con[111];
    node *next;
};

node *root=NULL;
node *last=NULL;

void crt_list(int x)
{
    node *newnode=new node;
    newnode->x=x;
    newnode->t=0;
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

void connect(int x,int y)
{
   node *t=root;
   node *fro,*to;

   while(t->next!=NULL)
   {
       if(t->x==x)
         fro=t;
       if(t->x==y)
         to=t;

       t=t->next;
   }
   if(t->x==x)
        fro=t;
   if(t->x==y)
        to=t;

   fro->con[fro->t]=to;
   fro->t++;

       to->con[to->t]=fro;
       to->t++;



}

void display()
{
   node *t=root;

   while(t->next!=NULL)
   {
      cout<<t->x<<' ';
      t=t->next;
   }
    cout<<t->x<<endl;
}

void connection_display()
{
   node *t=root;

   while(t->next!=NULL)
   {
     cout<<"connect of "<<t->x<<" is with : ";

     for(int i=0;i<t->t;i++)
          cout<<t->con[i]->x<<' ';

      cout<<endl;

      t=t->next;
   }
     cout<<"connect of "<<t->x<<" is with : ";

     for(int i=0;i<t->t;i++)
          cout<<t->con[i]->x<<' ';

      cout<<endl;
}



int main()
{
   int n,i,a,b;

   cin>>n;

   for(i=0;i<n;i++)
   {
       crt_list(i+1);
   }

   for(i=0;i<n*2;i++)
   {
       cin>>a>>b;
       connect(a,b);
   }

   connection_display();





}
