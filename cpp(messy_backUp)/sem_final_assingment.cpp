#include<iostream>
#include<string>

using namespace std;

class node
{
    public:
    int value,tm;
    char ch;
    string path;
    node *next,*left,*right,*prev,*parent;
};

node *root=NULL;
node *tree_root=NULL;
node *last=NULL;
string path;

void display_time()
{
    node *t=root;

    cout<<endl;

    while(t->next!=NULL)
    {
        cout<<t->ch<<' '<<t->value<<endl;
        t=t->next;
    }

  /*  cout<<t->ch<<' '<<t->value<<endl;

     while(t->prev!=NULL)
    {
        cout<<t->ch<<' '<<t->value<<endl;
        t=t->prev;
    }
  */
    cout<<t->ch<<' '<<t->value<<endl<<endl<<endl;
}

void create_link_list(char ch)
{
    //cout<<"here\n";
    node *newnode=new node;

    newnode->ch=ch;
    newnode->value=1;
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->left=NULL;
    newnode->right=NULL;

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


void find_las_node()
{
    node *t=root;

    while(t->next!=NULL)
    {
        t=t->next;
    }

    last = t;

}

void create_huffman_tree()
{
   node *t=last;
   node *s=last->prev;

  // cout<<"here";

   while(s!=root)
   {

       //cout<<s->ch<<' '<<t->ch<<endl;

       node *newnode = new node;

       newnode -> next = NULL;
       newnode -> prev = NULL;
      // newnode -> ch = '?';
       newnode -> left = s;
       newnode -> right = t;
       newnode -> tm =0;
       s -> parent = newnode;
       t -> parent = newnode;
       newnode -> value = s->value + t->value;

      last = s -> prev ;

       s->next=NULL;
       t->next=NULL;
       s->prev=NULL;
       t->prev=NULL;





       node *x = root;

       if(root -> value < newnode -> value)
       {
           newnode->next = root;
           newnode->prev = NULL;

           root -> prev = newnode;
           root = newnode;
       }
       else if(last -> value > newnode -> value)
       {
           last -> next = newnode;
           newnode -> prev = last;

           last = newnode;

       }
       else
      {
           while(newnode->value < x->next->value)
       {
           x=x->next;

       }
       newnode -> prev =x;
       newnode -> next = x->next;
       x->next = newnode;
       newnode -> next -> prev = newnode;

      }


      t=last;
      s=last->prev;
      last->next=NULL;

      //display_time();




   }
       node *newnode = new node;

       newnode -> next = NULL;
       newnode -> prev = NULL;
       newnode -> tm = 0;
       newnode -> left = s;
       newnode -> right = t;
       //newnode -> ch = '?';
       s -> parent = newnode;
       t -> parent = newnode;
       newnode -> value = s->value + t->value;

       tree_root=newnode;

}

void create_path()
{

    string path="\0";


    node *t = tree_root;


    while( tree_root -> tm < 4)
    {
        if(t -> tm %4 == 0)
        {

            t -> tm++;

            if(t->left != NULL)
                {
                    t =  t -> left;
                    path = path + "1";
                }

        }
        else if(t -> tm % 4 == 1)
        {

            t -> tm++;

           t->path=path;

           if(t->left==NULL&&t->right==NULL)
            {
                cout<<t->path<<' ';
                cout<<t -> ch<<' '<<endl;
            }



        }
         else if(t -> tm % 4 == 2)
        {

            t -> tm++;

           if(t->right != NULL)
                {
                    t =  t -> right;
                    path = path + "0";
                }
        }
         else if(t -> tm % 4 == 3)
        {

            t -> tm++;

           if(t->parent != NULL)
                {
                    t =  t -> parent;

                    if(path.size()>0)
                     path.erase(path.size()-1,1);
                }
        }
    }

    tree_root->tm=0;


}


void print_ans(char ch)
{



    node *t = tree_root;


    while ( tree_root->tm < 4 )
    {
        if(t->ch==ch&&t -> tm % 4 == 1)
        {
            cout<<t->path<<' ';

        }
        if(t -> tm %4 == 0)
        {

            t -> tm++;

            if(t->left != NULL)
                {
                    t =  t -> left;

                }

        }
        else if(t -> tm % 4 == 1)
        {

            t -> tm++;


        }
         else if(t -> tm % 4 == 2)
        {

            t -> tm++;

           if(t->right != NULL)
                {
                    t =  t -> right;

                }
        }
         else if(t -> tm % 4 == 3)
        {

            t -> tm++;

           if(t->parent != NULL)
                {
                    t =  t -> parent;

                }
        }
    }

    tree_root->tm=0;
}







int main()
{
    string str,path;



    getline(cin,str);

    for(int i=0;i<str.size();i++)
       create_link_list(str[i]);

    cout<<"total number of char \n";

    display_time();

    find_las_node();

    if(root->next==NULL)
        {
            node *newnode = new node;
            newnode->right = NULL;
            newnode -> left = root;
            tree_root = newnode;;
        }
    else
    create_huffman_tree();


       create_path();

    cout<<endl<<endl;

    if(root->next==NULL)
        {
            for(int i=0;i<str.size();i++)
                cout<<1<<' ';
        }
    else
       for(int i=0;i<str.size();i++)
       print_ans(str[i]);



}
