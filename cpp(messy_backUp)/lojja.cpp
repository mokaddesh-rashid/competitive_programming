#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)

const int MAX = 2000010;

typedef long double LD;


int n;
LD dp[MAX], pip[35];
bool vis[MAX];

LD rec(int p)
{
    if(p == n*2) return 0;

    if(vis[p]) return dp[p];
    vis[p] = 1; dp[p] = 0;

    int val = 0, v = 1;
    for(int i = 1;;i++)
    {
        LD x = pip[i]; val += v;
        dp[p] += (LD)x * (i + rec(p + 1));
        if(val >= p)
        {
            dp[p] += (LD)x * i;
            break;
        }
        v *= 2;
       /// cout << val << ' ' << p << ' ' << v << endl;
    }

    return dp[p];
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    FOR(i,1,32) pip[i] = pow(2, -i);

    cin >> n;
    cout << fixed;
    cout << setprecision(9) << rec( n ) << endl;
    return 0;
}
