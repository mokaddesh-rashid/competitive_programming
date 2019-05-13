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



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y, n, m, a = 0;

    cin >> n;

    int arr[n+1];

    for( i=0; i<n; i++ )
        cin >> arr[i];

    for( i=0; i<n; i++ )
    {
        a += arr[i];

        a = max( 0, a );

        x = max( x, a );
    }

    cout << x << endl;


    return 0;

}


