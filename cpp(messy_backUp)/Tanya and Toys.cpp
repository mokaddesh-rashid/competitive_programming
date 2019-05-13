#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;

int lower( int arr[], int st, int en, int val)
{
    int mid;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        if( arr[mid] == val )
            en = mid - 1 ;

        else if( arr[mid] > val )
            en = mid - 1 ;

        else if( arr[mid] < val )
            st = mid + 1 ;
    }

    return st;
}

int st[10000000];

int main()
{
   // ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a=0, b=0;

   // cin >> n >> m ;

    sff(n,m);

    int arr[n+1];

    for( i=0; i<n; i++)
        sf(arr[i]);
        //cin >> arr[i];

    sort( arr, arr+n);

    i = 1;
    while( m >= 0 )
    {
        y = lower( arr, 0, n-1, i);

        if( arr[y] != i )
        {
            m -= i;

            if( m >=0 )
            {
                st[a] = i;
                a++;
            }

        }

        i++;

    }
    pf("%d\n",a);
    //cout << a << endl;

    for( i=0; i<a; i++)
        pf("%d ",st[i]);
       //cout << st[i] <<' ';



    return 0;

}


