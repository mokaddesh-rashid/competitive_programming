#include<iostream>

using namespace std;

class node
{
public:
    int value ;
    node *next ;
    node *prev ;

};

node *frontt = NULL;
node *rear = NULL;


void enque( int x )
{
    node *newnode = new node;

    newnode -> value = x;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(frontt == NULL)
    {
        frontt = newnode;
        rear = newnode;
    }

    else
    {
        rear->next = newnode;

        newnode->prev = rear;

        rear = newnode;
    }
}

void pop()
{
    if ( frontt == NULL )
         cout << "empty queue\n";

    else if (frontt == rear)
        frontt = NULL;

    else
    {
        frontt = frontt->next;

        frontt->prev=NULL;


    }
}

void display()
{
   if(frontt==NULL)
    cout<<"EMPTY queue\n";

   else
   {
        node *t = frontt;

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

    enque( 1 );
    display();

    enque( 2 );
    display();
    pop();
    display();
    pop();
    display();
    enque( 3 );
    display();
    enque( 4 );
    display();

    enque( 5 );
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
    enque( 1 );
    display();
     enque( 2 );
    display();
     enque( 3 );
    display();
}

