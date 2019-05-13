#include<iostream>
#include<string>

using namespace std;

class node
{
    public:
    int value;
    char ch;
    node *next,*left,*right,*prev;
};

node *root=NULL;
node *tree_root=NULL;
node *pos;

void create_link_list(char ch)
{
    //cout<<"here\n";
    node *newnode=new node;

    newnode->ch=ch;
    newnode->value=1;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(root==NULL)
    {
       // cout<<"here1\n";
        root=newnode;
    }

    else
    {
        //cout<<"here2\n";
        node *t=root;

        while(t->ch!=ch&&t->next!=NULL)
        {
            t=t->next;
        }

        if(t->ch==ch)
           {
                t->value++;
           }
        else
           {
               t->next=newnode;
               //cout<<"create\n";
           }

    }

}

void display()
{
    node *t=root;

    while(t->next!=NULL)
    {
        cout<<t->ch<<' '<<t->value<<endl;
        t=t->next;
    }

    cout<<t->ch<<' '<<t->value<<endl;
}


int main()
{
    string str;

    getline(cin,str);

    for(int i=0;i<str.size();i++)
       create_link_list(str[i]);

    display();

}
