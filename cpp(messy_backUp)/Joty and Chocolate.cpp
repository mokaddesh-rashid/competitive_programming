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
#define NL '\n


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL z, i, j, x, y, n, m, a, b, c, d, p, q;

    cin >> n >> a >> b >> p >> q;

    c = __gcd( a, b );
    d = a * b;
    c = d / c;

    x = n / a;
    y = n / b;
    z = n / c;

    x -= z;
    y -= z;

    cout << max( ((x+z)*p)+(y*q), (x*p)+((y+z)*q) );






    return 0;

}


