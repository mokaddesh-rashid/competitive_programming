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
                      // cout<<"right ";
                       t=t->right;
                   }
            }

        }
    }


}

void display()
{
   node *t=root;

   while(root->cmd<4)
   {
       if(t->cmd==0)
       {
           t->cmd++;

           if(t->left!=NULL)
               t=t->left;
       }

       else  if(t->cmd==1)
       {
           t->cmd++;

           cout<<t->value<<' ';
       }

        else  if(t->cmd==2)
       {
           t->cmd++;

           if(t->right!=NULL)
               t=t->right;
       }

         else  if(t->cmd==3)
       {
           t->cmd++;


           t=t->parent;
       }

   }
}


int main()
{
    create_tree(52);
    cout<<endl;
    create_tree(55);
    cout<<endl;
    create_tree(55);
    cout<<endl;
     create_tree(55);
    cout<<endl;
     create_tree(1);
    cout<<endl;
    create_tree(2);
    cout<<endl;
    create_tree(5);
    cout<<endl;
     create_tree(4);
    cout<<endl;

    display();

}
