#include<iostream>
#include<ctime>

using namespace std;

int n;

void swaap( int &a, int &b )
{
    int c;

    c = a;
    a = b;
    b = c;
}

int bubble ( int arr[] )
{
    int chk = 0, cnt=0;
    for( int i=0; i<n-1; i++ )
    {
        chk=0;
        for( int j = 0; j<n-1; j++ )
        {
          cnt++;
          if( arr[j] > arr[j+1] )
                {
                    swaap( arr[j], arr[j+1] );
                    chk = 1;
                }
        }

        if( chk == 0 )
            break;
    }
    return cnt;
}

void selection( int arr[] )
{

    int p;
    for( int i=0; i<n-1; i++ )
    {
        p = i;
        for( int j = i; j<n; j++ )
        {
          if( arr[p] > arr[j] )
                p = j;
        }
        swaap( arr[p], arr[i] );
    }

}
void insertion( int arr[] )
{

    int k, j;
    for( int i=1; i<n; i++ )
    {
        k = arr[i];
        j = i - 1;

        while( j >= 0 && arr[j] > k )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;

    }

}

int arr[100000], brr[100000], crr[100000];
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

       }
    cout<<bubble(arr)<<endl;

     return 0;

}




