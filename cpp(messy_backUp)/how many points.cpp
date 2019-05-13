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
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        long long i, j, x, y, n, m, a, b;

        cin >> n >> x >> m >> y ;
        a = max( n-m, m-n );
        b =  max( x-y, y-x );
        cout << "Case " << ca << ": "<< __gcd( a, b ) + 1 << endl;
        ca++;
    }




    return 0;

}


