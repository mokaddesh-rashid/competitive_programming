#include<iostream>
#include<string>

using namespace std;

class node
{
public:
    string first,second,min_s;
    node *next;

};


node *root=NULL;
node *end0=NULL;

void enque(string f,string s)
{

    node *newnode=new node;

    newnode->first=f;
    newnode->second=s;

    if(s.size()<f.size())
        newnode->min_s=s;
    else
        newnode->min_s=f;

    newnode->next=NULL;

    if(root==NULL)
    {
        root=newnode;
        end0=newnode;
    }

    else
    {
        node *t=end0;

        t->next=newnode;
        end0=newnode;
    }

}

void check(string x)
{
    node *t=root;

    while(t->first!=x)
    {
        t=t->next;
    }

    cout<<t->min_s<<' ';
}
void display()
{
    cout<<endl;
    node *t=root;

    while(t->next!=NULL)
    {
         cout<<t->min_s<<' ';
          cout<<t->first<<' ';
           cout<<t->second<<' ';
           cout<<endl;
        t=t->next;
    }
     cout<<t->min_s<<' ';
          cout<<t->first<<' ';
           cout<<t->second<<' ';
           cout<<endl;
    cout<<endl<<endl;


}



int main()
{
    string frst,scnd;

    int n,m,i;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>frst>>scnd;

        enque(frst,scnd);
    }
    // display();
    for(n=0;n<m;n++)
    {
        cin>>frst;
        check(frst);
    }
}
