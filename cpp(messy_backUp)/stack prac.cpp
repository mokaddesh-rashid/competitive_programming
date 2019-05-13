#include<iostream>
#include<cstring>

using namespace std;


int ar[1110];
int siz,top,x,c,d,i;


void push( int c )
{

        top++;
        ar[top]=c;

}

void pop()
{
        if( top < 0 )
            cout<<"nothing to pop\n";
        else

          top--;
}

 void display()
    {
        cout<<"current stack : ";
        for(i=0;i<=top;i++)
            cout<<ar[i]<<' ';

        cout<<endl;
    }



int main()
{
   top = -1;

   push( 5 );
   push( 4 );

   push( 3 );
   display();
   pop();
   display();
   push( 2 );
   push( 2 );

}



