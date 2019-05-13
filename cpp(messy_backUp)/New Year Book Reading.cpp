#include<iostream>

using namespace std;

int ans=0;

class node
{
public:
    node *next,*prev;
    int value,w;
};

node *root=NULL;
node *last=NULL;


void create(int x,int w)
{
    node *newnode=new node;

    newnode->next=NULL;
    newnode->value=x;
    newnode->w=w;
    newnode->prev=NULL;


    if(root==NULL)
    {
        root=newnode;
        //last=newnode;
    }

    else
    {
        node *t=root;

        while(t->value!=x&&t->next!=NULL)
        {
            t=t->next;
        }

        if(t->value!=x&&t->next==NULL)
        {
           t->next=newnode;
           newnode->prev=t;
        }

    }
}

void stack_re(int x)
{

    if(root->value==x)
    {
        ans+=0;
    }

    else
    {
        node *t=root;
        node *s;

        while(t->value!=x)
        {
            ans+=t->w;
            t=t->next;
        }

        s=t->prev;
        s->next=t->next;

        if(s->next!=NULL)
        {
            s->next->prev=s;
        }

        t->prev=NULL;
        t->next=root;
        root->prev=t;
        root=t;



    }
}


void display()
{
       node *t=root;

        while(t->next!=NULL)
        {
            cout<<t->value<<' '<<t->w<<endl;
            t=t->next;
        }

       cout<<t->value<<' '<<t->w<<endl<<endl;
}

int main()
{
    int n,m;

    cin>>n>>m;

    int arr[n+1],hmm[m+1],i,x,a,w;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=0;i<m;i++)
    {
        cin>>hmm[i];
        x=hmm[i];
        w=arr[x-1];

        create(x,w);

    }

   // display();


    for(i=0;i<m;i++)
    {

        x=hmm[i];
        stack_re(x);
       // display();

    }

    cout<<ans;




}
