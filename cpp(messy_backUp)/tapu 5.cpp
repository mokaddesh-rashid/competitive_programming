#include<iostream>

using namespace std;
#define sz 1000


class node
{
    public:
    int pos, cost;
    node *next;
};

node *start[sz];

void addlast(int from,int pos,int cost)
{
    node *newnode=new node;

    newnode->cost=cost;
    newnode->pos=pos;
    newnode->next=NULL;

    if(start[from]==NULL) start[from]=newnode;
    else
    {
        node *t=start[from];

        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=newnode;
    }
}

void display(int from)
{
    cout<<"current connection of "<<from<<": ";
    node *t=start[from];

    while(t!=NULL)
    {
        cout<<t->pos<<'('<<t->cost<<')'<<' ';
        t=t->next;
    }
    cout<<endl;

}

int mat[sz][sz];

int main()
{
   for(int i=0;i<sz;i++) start[i]=NULL;
//   addlast(1,2,-3);
//   addlast(1,4,-3);
//   display(1);
    int i,j,a,b,c,n,m,x,y,z;

    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
      cin>>x>>y>>c;
      mat[x][y]=c;
      addlast(x,y,c);
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for(i=1;i<=n;i++)
    {
       display(i);
    }
}


