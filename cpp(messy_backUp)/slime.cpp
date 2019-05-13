
#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


class node
{
public:
    int va;
    node *next, *prev;
};

node *root = NULL;
node *last = NULL ;

void add_last( )
{
    node *newnode = new node;

    newnode -> va = 1;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    if( root == NULL )
    {
        root = newnode;
        last = newnode;
    }
    else
    {
        last->next = newnode;

        newnode->prev = last;

        last = newnode;

    }

    node *t = last;

    if( last != root )
     {
          node *s = last->prev;

      while( t->va == s->va  )
    {

        s->va++;


        s->next = t->next;

        if( s->next != NULL)
            s->next->prev = s;

        if( t == last )
            last = s;

        if( s == root )
            break;

        t = s;
        s = s->prev;


    }

     }










}

void print( )
{

    node *t = root;

    while ( t->next != NULL )
    {
      cout << t->va << ' ';

      t = t->next;

    }

    cout << t->va << endl;


}


int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, x, y, n, m;

    cin >> n;

    for( i=0; i<n; i++)
       {

         add_last();

       }

        print();

    return 0;

}
