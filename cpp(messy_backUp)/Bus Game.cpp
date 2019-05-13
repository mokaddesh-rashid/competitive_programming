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



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y, n, m;

    cin >> n >> m ;


    while( n >= 0 && m >= 0 )
    {
        if( x % 2 == 0 )
        {
            n -= 200;
            m -= 20;
        }
        else
        {
            n -= 20;
            m-= 200;
        }

        x++;
    }

    if( x % 2 == 1 )
        cout << "Ciel";
    else
        cout << "Hanako";

    return 0;

}


