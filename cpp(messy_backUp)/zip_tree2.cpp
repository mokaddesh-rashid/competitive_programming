#include<iostream>
#include<string>

using namespace std;

class node
{
    public:
    int value;
    char ch;
    string path;
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

    else if(root->ch==ch)
        root->value++;

    else
    {
        //cout<<"here2\n";
        node *t=root;


        while(t->ch!=ch&&t->next!=NULL)
        {
            t=t->next;
        }

        if(t->ch==ch&& t->value+1>t->prev->value)
           {

                t->value++;

               node *s=t->prev;


                s->next=t->next;

               if(s->next!=NULL)
                   s->next->prev=s;


                s=root;

                if(t->value>root->value)
                {
                    t->next=root;
                    root->prev=t;

                    root=t;
                    root->prev=NULL;
                }

                else
                {
                    while(s->next->value>t->value)
                    {
                        s=s->next;
                    }

                    t->prev=s;
                    t->next=s->next;

                    s->next=t;
                    t->next->prev=t;
                }


           }

         else if(t->ch==ch)
             t->value++;

         else
           {
              t->next=newnode;
              newnode->prev=t;
           }

    }

}

void create_path()
{
    string path;

    path="0";
    node *t=root;

    while(t->next!=NULL)
    {
        t->path=path;

         t=t->next;

        if(t->next!=NULL)
           path="1"+path;


    }
   if(path!="0")
     path[path.size()-1]='1';

    if(root->next->next==NULL)
       t->path="1";

    else
    t->path=path;

}

void display_ans(char ch)
{
    node *t=root;

    while(t->ch!=ch)
    {
        t=t->next;
    }
     cout<<t->path<<' ';


}

void create_tree()
{
    int pos=0;

    node *nullnode=new node;

    nullnode->next  =  NULL;
    nullnode->value = pos;
    nullnode->left  =  NULL;
    nullnode->right  =  NULL;

   tree_root=nullnode;

   node *t = root;
   node *s = tree_root;


   while(t->next!=NULL)
   {
       node *newnode = new node;
       newnode->value = pos;
       newnode -> left = NULL;
       newnode -> right = NULL;

       s->left = t;
       s->right = newnode;

       s = newnode;
       t = t->next;
       pos++;

   }

   s->right=t;

   //cout<<t->ch<<endl;
}


void display_time()
{
    node *t=root;

    while(t->next!=NULL)
    {
        cout<<t->ch<<' '<<t->value<<endl;
        t=t->next;
    }

    cout<<t->ch<<' '<<t->value<<endl;
}


void display_path()
{
     node *t=root;

    while(t->next!=NULL)
    {
       cout<<t->ch<<' '<<t->path<<endl;
        t=t->next;
    }

    cout<<t->ch<<' '<<t->path<<endl<<endl;



}


int main()
{
    string str,path;

    path="0";

    getline(cin,str);

    for(int i=0;i<str.size();i++)
       create_link_list(str[i]);

    cout<<"total number of char \n";

    display_time();

    cout<<endl<<endl;

    if(root->next==NULL)
        root->path="1";
   else
    create_path();//2ta and 1ta thakle path ki hoba ask sir?

    create_tree();

    cout<<"path of char\n";

    display_path();


     for(int i=0;i<str.size();i++)
      display_ans(str[i]);









}
