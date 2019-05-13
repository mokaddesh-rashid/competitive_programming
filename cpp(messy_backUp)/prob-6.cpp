#include<iostream>
#include<ctime>

using namespace std;

int n;

void swaap( double &a, double &b )
{
    double c;

    c = a;
    a = b;
    b = c;
}

void bubble ( double arr[] )
{
    int chk = 0;
    for( int i=0; i<n-1; i++ )
    {
        for( int j = 0; j<n-i-1; j++ )
        {

          if( arr[j] > arr[j+1] )
                {
                    swaap( arr[j], arr[j+1] );
                    chk = 1;
                }
        }

        if( chk == 0 )
            break;
    }
}

double arr[100000], brr[100000], crr[100000];
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, m;
    double d;

    cin >> n ;

    for( i=0; i<n; i++ )
       {
            cin >> arr[i];
            brr[i] = arr[i];
            crr[i] = arr[i];
       }

     bubble( arr );
     for( i=0; i<n; i++ )
        cout << arr[i] << ' ';

     return 0;

}




