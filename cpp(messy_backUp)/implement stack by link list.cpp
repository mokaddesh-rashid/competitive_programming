#include<iostream>

using namespace std;

class node
{
public:
    int value ;
    node *next ;
    node *prev ;

};

node *bottom = NULL;
node *top = NULL;


void push( int x )
{
    node *newnode = new node;

    newnode -> value = x;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(bottom == NULL)
    {
        bottom = newnode;
        top = newnode;
    }

    else
    {
        top->next = newnode;

        newnode->prev = top;

        top = newnode;
    }
}

void pop()
{
    if ( bottom == NULL )
         cout << "empty stack\n";

    else if (bottom == top)
        bottom = NULL;

    else
    {
        top = top->prev;

        top->next = NULL;

    }
}

void display()
{
   if(bottom==NULL)
    cout<<"EMPTY stack\n";

   else
   {
        node *t = bottom;

    while( t->next != NULL )
    {
        cout<<t->value<<' ';

        t = t->next;
    }

    cout<<t->value<<endl;
   }
}

int main()
{
    pop();
    display();
    push( 1 );
    display();
    push( 2 );
    display();
    push( 3 );
    display();
    push( 4 );
    display();
    pop();
    display();
    push( 5 );
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    push( 1 );
    display();
}
