#include<iostream>

using namespace std;

class node
{
public:
    int value;
    node *left_son;
    node *right_son;
    node *parent;
};

node *root=NULL;

void create_tree(int x)
{
    node *newnode=new node;
    newnode->value=x;
    newnode->left_son=NULL;
    newnode->right_son=NULL;

    if(root==NULL)
    {
        root=newnode;

    }
    else
    {
        node *t=root;

        while(t->left_son!=NULL||t->right_son!=NULL)
        {
            string way;

            cout<<" at "<<t->value<<endl;

            if(t->left_son!=NULL)
                cout<<"left value "<<t->left_son->value<<' ';

            if(t->right_son!=NULL)
                cout<<"right value "<<t->right_son->value<<' ';
            cout<<endl;

            cout<<"which way to go !!\n"<<endl;
            cin>>way;

            if(way=="left"&&t->left_son!=NULL)
                t=t->left_son;
            else if(way=="right"&&t->right_son!=NULL)
                t=t->right_son;
            else if(way=="add")
                break;
            else
                cout<<"invalid\n";
        }

        if(t->left_son==NULL)
            t->left_son=newnode;

        else if(t->right_son==NULL)
            t->right_son=newnode;
        else
            cout<<"cant add here\n";

    }


}

int main()
{
   create_tree(1);
   create_tree(2);
   create_tree(3);
   create_tree(4);
   create_tree(5);
    create_tree(6);
   create_tree(7);
   create_tree(8);
   create_tree(9);
   create_tree(10);
    create_tree(11);
   create_tree(12);
   create_tree(13);
   create_tree(14);
   create_tree(15);
}
