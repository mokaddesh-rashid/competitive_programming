#include<iostream>

using namespace std;

class node
{
public:
    int value,cmd;
    node *left,*right;
    node *parent;
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
            if(t->value>x)
            {
                if(t->left==NULL)
                   {
                        //cout<<"at left ";
                       t->left=newnode;
                       newnode->parent=t;
                        break;
                   }
                else
                   {
                       //cout<<"left ";
                      t=t->left;
                   }
            }

            else
            {
                if(t->right==NULL)
                   {
                        //cout<<"at right ";
                       t->right=newnode;
                        newnode->parent=t;
                        break;
                   }
                else
                   {
                       //cout<<"right ";
                       t=t->right;
                   }
            }

        }
    }


}

void find_it(int x)
{
   node *t=root;

   if(root==NULL)
    {
        cout<<"empty \n";
    }
    else
    {


        while(true)
        {
            if(t->value==x)
            {
                cout<<"in the tree\n";
                break;
            }
            else if(t->value>x)
            {
                if(t->left==NULL)
                   {

                      cout<<"not in the tree\n";
                        break;
                   }
                else
                   {
                      t=t->left;
                   }
            }

            else
            {
                if(t->right==NULL)
                   {

                       cout<<"Not in the tree\n";
                        break;
                   }
                else
                   {

                       t=t->right;
                   }
            }

        }
    }


}


int main()
{
    create_tree(52);
   // cout<<endl;
    create_tree(55);
    //cout<<endl;
    create_tree(55);
    //cout<<endl;
     create_tree(55);
    //cout<<endl;
     create_tree(1);
    //cout<<endl;
    create_tree(2);
    //cout<<endl;
    create_tree(5);
    //cout<<endl;
     create_tree(4);
   // cout<<endl;

   find_it(0);
    cout<<endl;
    find_it(1);



}

