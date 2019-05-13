#include<iostream>

using namespace std;

class node
{
public:
    int value;
    node *left,*right;
};

node *root=NULL;

void create_tree(int x)
{
    node *newnode=new node;

    newnode->value=x;
    newnode->left=NULL;
    newnode->right=NULL;

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
                   t->right=newnode;
                   break;

               }

               else
                t=t->right;
           }
        }
    }
}

void find_num(int x)
{
    if(root==NULL)
    {
       cout<<"empty tree!!!\n";
    }

    else
    {
        node *t=root;

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
                  cout<<"not in the tree!!\n";
                   break;

               }

               else
                t=t->left;
           }

           else
           {
               if(t->right==NULL)
               {
                   cout<<"not in the tree!!\n";
                   break;

               }

               else
                t=t->right;
           }
        }
    }
}



int main()
{
    create_tree(21);
    create_tree(3);
    create_tree(1);
    create_tree(9);
    create_tree(123);
    create_tree(7);

    find_num(22);

}
