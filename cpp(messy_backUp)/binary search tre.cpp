#include<iostream>

using namespace std;


class node
{
public:
    int value,cmd;
    node *left,*right,*parent;
};

node *root=NULL;

void create_tree(int x)
{
    node *newnode=new node;

    newnode->cmd=0;
    newnode->value=x;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->parent=NULL;



    if(root==NULL)
    {
        root=newnode;
    }

    else
    {
        node *t=root;

        while(true)
        {
            if(t->value>newnode->value)
            {

               if(t->left==NULL)
               {
                   newnode->parent=t;
                   t->left=newnode;
                   break;
               }

               else
                t=t->left;
            }

            else
            {
               if(t->right==NULL)
               {
                    newnode->parent=t;
                   t->right=newnode;
                   break;
               }

               else
                t=t->right;
            }
        }
    }
}

void display()
{
    node *t=root;

    while(root->cmd!=4)
    {
        if(t->cmd==0)
        {
             //cout<<" from "<<t->value<<endl;
             t->cmd++;
            if(t->left!=NULL)
                t=t->left;


        }

        else if(t->cmd==1)
        {
           cout<<t->value<<' ';

            t->cmd++;
        }

        else if(t->cmd==2)
        {
            t->cmd++;
            if(t->right!=NULL)
                t=t->right;


        }
        if(t->cmd==3)
        {
             t->cmd++;
           t=t->parent;

        }
    }
}

int main()
{
    create_tree(50);
     create_tree(27);
     create_tree(29);
     create_tree(58);
     create_tree(17);
     create_tree(50);
     create_tree(275);
     create_tree(295);
     create_tree(548);
     create_tree(147);
     //create_tree(20);

     display();
}
