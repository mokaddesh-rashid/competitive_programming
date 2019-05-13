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


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

   // INP;
    //OUT;

    int t;

    cin >> t;

    while( t-- )
    {
        long long int i, j, x = 0, y, n, m;

    cin >> n >> m ;

    while( n > 0 && m > 0 )
    {
        if( n > m )
        {
            y = n / m;
            x += y;
            n = n%m;
        }
        else
        {
            y = m / n;
            x += y;
            m = m%n;

        }
    }

    cout << x << endl;
    }

    return 0;

}


