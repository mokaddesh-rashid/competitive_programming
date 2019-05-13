#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;




int top = -1, sz = 5;
int *stackk = new int [sz];

void resize_stack()
{
    int *temp = new int [sz*2];

    for(int i=0; i<=top; i++)
    {
        temp[i] = stackk[i];
    }

    delete [] stackk;

    stackk = temp;
    sz *= 2;
}


void push ( int x )
{
    top++;

    if ( top == sz )
        resize_stack();

    stackk[ top ] = x;
}



void pop( )
{
   if( top != -1 )
      top--;
}

int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, x, y, n, m;

    while ( true )
    {
        string str;
        int x;

        cin >> str;

        if( str == "push" )
        {
            cin >> x;
            push( x );
        }

        else if( str == "pop" )
        {
            pop();
        }

        else
            break;

        cout << "current stack : ";

        for( i=0; i<=top; i++)
            cout << stackk[i] << ' ';
        cout << endl;
    }

    return 0;

}
