#include<iostream>

using namespace std;


class node
{
public:
    int value,tm;
    node *left,*right,*parent;
};

node *root=NULL;


void create_binary_tree(int x)
{
    node *newnode = new node;

    newnode -> value = x;
    newnode->parent = NULL;
    newnode -> tm = 0;
    newnode -> left = NULL;
    newnode -> right = NULL;

    if( root == NULL )
    {
        root = newnode;

    }

    else
    {
        node *t = root;

        while(true)
        {
            if( x < t->value )
            {
                if( t->left == NULL)
                {
                    t->left = newnode;
                    newnode->parent = t;
                    break;
                }

                else
                    t = t->left;
            }

            else
            {
                if( t->right == NULL)
                {
                    t->right = newnode;
                    newnode->parent = t;
                    break;
                }

                else
                    t = t->right;
            }
        }
    }
}

void delete_node (int x)
{
    node *t = root;

    while( root->tm < 4 && t->value != x)
    {
        if( t->tm % 4 == 0 )
        {
            t->tm++;

            if( t->left != NULL)
                t = t->left;
        }

        else if( t->tm % 4 == 1 )
        {
            t->tm++;

        }
         else if( t->tm % 4 == 2 )
        {
            t->tm++;

            if( t->right != NULL)
                t = t->right;
        }
         else if( t->tm % 4 == 3 )
        {
            t->tm++;

            if( t->parent != NULL)
                t = t->parent;
        }
    }

    root ->  tm = 0;

    if( t->value == x)
    {
        if( root-> left == NULL && root->right == NULL)
        {
            root = NULL;
        }
         else if( t->left == NULL && t->right == NULL )
        {
            t = t->parent;

            if(t->left->value == x)
                t->left = NULL;

            else
                t->right = NULL;
        }

        else if( t->left == NULL || t->right == NULL )
        {
            //t = t->parent;
            node *s = t -> parent;

            if(s->left == t)
            {
                if(t->left == NULL)
                    s->left = t->right;
                else
                    s->left = t->left;

            }
            else if(s->right == t)
            {
                if(t->left == NULL)
                    s->right = t->right;
                else
                    s->right = t->left;

            }
        }

        else
        {

        }
    }
}

void display()
{
    node *t = root;

    while( root->tm < 4)
    {
        if( t->tm % 4 == 0 )
        {
            t->tm++;

            if( t->left != NULL)
                t = t->left;
        }

        else if( t->tm % 4 == 1 )
        {
            t->tm++;

           cout<< t->value <<' ';
        }
         else if( t->tm % 4 == 2 )
        {
            t->tm++;

            if( t->right != NULL)
                t = t->right;
        }
         else if( t->tm % 4 == 3 )
        {
            t->tm++;

            if( t->parent != NULL)
                t = t->parent;
        }
    }

    root ->  tm = 0;
}

int main()
{
   create_binary_tree(12);
   create_binary_tree(122);
   create_binary_tree(42);
   create_binary_tree(2);
   create_binary_tree(15);
   create_binary_tree(11);
    display();

    delete_node(4);
}
