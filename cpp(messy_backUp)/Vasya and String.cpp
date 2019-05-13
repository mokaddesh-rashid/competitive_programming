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

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;

int arr[100010], brr[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a = 0, b = 0, k, maxx = 0;
    string str;
    cin >> n >> k;
    cin >> str ;

    for( i=0; i<n; i++ )
    {
        if( str[i] == 'b' )
            a++;
        arr[i] = a;

        if( str[i] == 'a' )
            b++;
        brr[i] = b;

    }

    for( i=0; i<n; i++ )
    {

       if( str[i] != 'b' )
         y = upper_bound( arr, arr+n, arr[i]+k ) - arr;
       else
         y = upper_bound( arr, arr+n, arr[i]+k-1 ) - arr;

        maxx = max( maxx, y - i );
    }
    for( i=0; i<n; i++ )
    {
     if( str[i] != 'a' )
        y = upper_bound( brr, brr+n, brr[i]+k ) - brr;
     else
        y = upper_bound( brr, brr+n, brr[i]+k-1 ) - brr;


        maxx = max( maxx, y - i );
    }

    cout << maxx;




    return 0;

}


