#include<iostream>

using namespace std;

void removee( int arr[], int &n )
{
    int i, x, a, b, c;


    if ( arr[1] > arr[n-1] )
      swap( arr[1] , arr[n-1] );

     n--;

    x=1;


    while(( arr[x] < arr[2*x] || arr[x] < arr[2*x+1] ) )
    {

         if( arr[2*x] > arr[2*x+1] && 2*x < n )
        {
            swap( arr[x], arr[2*x] );
            x = 2*x;
        }

        else  if( arr[2*x] <= arr[2*x+1] && 2*x+1 < n )
        {

            swap( arr[x], arr[2*x+1] );
            x = 2*x+1;
        }
         else  if( arr[x] < arr[2*x] && 2*x < n )
        {
            swap( arr[x], arr[2*x] );
            x = 2*x;
        }
        else
            break;


    }
}

void heap_add(int arr[],int &i)
{
       int x;
       cin >> arr[i];

        x = i;
        i++;

        while( arr[x] > arr[x/2] && x/2 > 0 )
        {
            swap( arr[x], arr[x/2] );
            x = x/2;
        }
}

 void display( int arr[], int n )
 {
          cout << "current Max heap : ";

     for(int i=1; i<n; i++ )
          cout<<arr[i]<<' ';

          cout<<endl;
 }

int main()
{

    int arr[11111],i,x,a,b,c,add_pos=1;

    cout <<"to add -> a\nto remove -> r\nto sort any other char\n";

    for(i=1;i<11111;i++)
    {
       char ch;


       cin >> ch;

        if( ch == 'a' )
             heap_add(arr,add_pos);

       else if( ch == 'r' && add_pos == 1 )
             cout<<"Noting to remove\n";

       else if( ch == 'r' )
             removee( arr, add_pos );

       else
            break;

        display( arr, add_pos );
    }

        display( arr, add_pos );


   if( add_pos > 1 )
   {
        a = add_pos;

    while(a>1)
    {
       removee( arr , a );
    }

    cout<<"\n\n After removing all elements of ";

    display(arr,add_pos);
   }







}
