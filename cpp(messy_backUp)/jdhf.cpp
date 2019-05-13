#include<iostream>
#include<string>

using namespace std;

int ans=0;

class node
{
public:
    node *next,*prev;

    string str;

    int value,w;
};



node *b_root=NULL;
node *b_last=NULL;

node *f_root=NULL;
node *f_last=NULL;

node *current=NULL;

void create(string str)
{
    node *newnode=new node;

    newnode->next=NULL;
    newnode->str=str;
    newnode->prev=NULL;

    if(current!=NULL)
    {
        current->next=b_root;
        b_root=current;
    }

    current=newnode;
    f_root=NULL;
}


void back_s()
{
   if(b_root==NULL)
        cout<<"Ignored"<<endl;
   else
   {
       cout<<b_root->str<<endl;

       current->next=f_root;
       f_root=current;

       current=b_root;

       if(b_root->next==NULL)
          b_root=NULL;
        else
          b_root=b_root->next;
   }
}

void front_s()
{
   if(f_root==NULL)
        cout<<"Ignored"<<endl;
   else
   {

       current->next=b_root;
       b_root=current;
       cout<<f_root->str<<endl;
       current=f_root;

       if(f_root->next==NULL)
          f_root=NULL;
        else
          f_root=f_root->next;
   }
}




int main()
{
    int x=0,n;

    cin>>n;
    while(x<n)
    {
     cout<<"Case "<<x+1<<':'<<endl;
     string str="http://www.lightoj.com/";

     create(str);


    while(true)
    {
       cin>>str;

       if(str=="QUIT")
       {
           break;
       }

       else if(str=="VISIT")
       {
           string st;
           cin>>st;

           cout<<st<<endl;

           create(st);
       }

       else if(str=="BACK")
       {
           back_s();
       }

       else
        front_s();
    }
    x++;
    }
}
