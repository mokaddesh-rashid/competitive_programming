#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int maxx;

class node
{
public:
    string str;
    node *next;
    node *prev;
};

node *root=NULL;
node *last=NULL;

void create_list(string str)
{
    node *newnode=new node;

    newnode->str=str;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(root==NULL)
    {
        root=newnode;
        last=newnode;
    }

    else
    {
        newnode->prev=last;
        last->next=newnode;
        last=newnode;
    }
}

void find_maxx(node *s)
{
    //cout<<s->str<<' ';
    node *t=s;
    int time=0;

    while(t->next!=NULL)
    {
        if(t->str==s->str)
            time++;
        t=t->next;
    }
    if(t->str==s->str)
            time++;

    //cout<<time;


    maxx=max(maxx,time);
}

int main()
{
    string str;

    int n,i;
    maxx=0;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>str;

        create_list(str);
    }

    node *t=root;

    while(t->next!=NULL)
    {
        find_maxx(t);
        t=t->next;
    }
      find_maxx(t);

    cout<<maxx;


}
