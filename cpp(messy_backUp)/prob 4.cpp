#include<iostream>
#include<ctime>

using namespace std;

struct info
{
    int val, pos;
} arr[100010];

int n;
void insertion( info arr[] )
{
    int k, j;
    for( int i=1; i<n; i++ )
    {
        k = arr[i].val;
        j = i - 1;
        while( j >= 0 && arr[j].val > k )
        {
            arr[j+1].val = arr[j].val;
            arr[j+1].pos = arr[j].pos;
            j--;
        }
        arr[j+1].val = k;
        arr[j+1].pos = i+1;
    }
}

int main()
{
    int i, j, x, y, m;
    cin >> n ;

    for( i=0; i<n; i++ )
       {
            cin >> arr[i].val;
            arr[i].pos = i+1;

       }
     insertion( arr );

     for( i=0; i<n; i++ )
        cout << "employee " << arr[i].pos << ' ' << arr[i].val << "TK" << endl;

     return 0;

}




