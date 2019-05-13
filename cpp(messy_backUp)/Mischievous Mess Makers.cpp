#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
//#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, x = 0, y, n, m, z = 0, mx = 0;

    cin >> n >> m ;

    y = n-1;

    int arr[n+1], bal[n+1];

    memset( bal, 0, sizeof(bal));



    for( i=0; i<n; i++)
    {
        if( i < m )
        {
            mx += y;
            y--;
        }
        else
        {
            mx = mx + min( m, n-(i+1));
        }
    }



    cout << mx;

    return 0;

}


