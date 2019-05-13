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
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, a, b;

    cin >> n >> m >> x ;

    a = x-n;

    if( a == 0 )
        cout << "YES";
    else if( a/m > 0 )
    {
        a = a%m;

        if( a == 0 || a == 1 )
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";





    return 0;

}


