#include<iostream>
#include<string>

using namespace std;


class node
{
public:
    int x;
    string username,pass;
    node *next;
};

node *root=NULL;


void regis()
{
    string str,st;
    int k=0;

    cin>>str>>st;

    node *newnode=new node;

    newnode->x=0;
    newnode->username=str;
    newnode->pass=st;
    newnode->next=NULL;

    if(root==NULL)
    {
        root=newnode;
        cout<<"success: new user added\n";

    }

    else
    {
       node *t=root;

       while(t->next!=NULL)
       {
           if(t->username==str)
               k=1;

           t=t->next;
       }
        if(t->username==str)
               k=1;

        if(k==1)
        {
            cout<<"fail: user already exists\n";

        }

        else
        {
            t->next=newnode;
             cout<<"success: new user added\n";
        }
    }


}

void login()
{
    string user,pass;
    int k=0;

    cin>>user>>pass;

    node *t=root;



    while(t->next!=NULL&&t->username!=user)
       {
           t=t->next;
       }

      if(t->username==user&&t->pass==pass&&t->x==1)
           {
               cout<<"fail: already logged in\n";

           }
   else if(t->username==user&&t->pass==pass&&t->x==0)
           {
               cout<<"success: user logged in\n";
               t->x=1;
           }
   else if(t->username==user&&t->pass!=pass)
           {
               cout<<"fail: incorrect password\n";
           }
   else
   {
       cout<<"fail: no such user\n";
   }




}

void logout()
{
   string user;
    int k=0;

    cin>>user;

    node *t=root;



    while(t->next!=NULL&&t->username!=user)
       {
           t=t->next;
       }

      if(t->username==user&&t->x==0)
           {
               cout<<"fail: already logged out\n";

           }
   else if(t->username==user&&t->x==1)
           {
               cout<<"success: user logged out\n";
               t->x=0;
           }
   else
   {
       cout<<"fail: no such user\n";
   }
}


int main()
{
    std::ios::sync_with_stdio(false);
    string str;

    int n,i;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>str;

        if(str=="register")
            regis();
        else if(str=="login")
            login();
        else if(str=="logout")
            logout();
    }
}
