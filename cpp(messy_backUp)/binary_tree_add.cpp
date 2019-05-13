#include<iostream>

using namespace std;

class node
{
    public;
    int value;
    node *right,*left,*parent;
};

node *root=NULL;
node *add_pos=NULL;

void create_tree(int x)
{
    node *newnode=new node;

    newnode->value=x;
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->parent=NULL;

    if(root==NULL)
    {
        root=newnode;
        add_pos=newnode;
    }

    else if(add_pos->left==NULL||add_pos->right==NULL)
    {
        if(add_pos->left==NULL)
          add_pos->left=newnode;

        else
         add_pos->right=newnode;

         newnode->parent=add_pos;

    }

    else if()
}

int main()
