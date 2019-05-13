#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define F first
#define S second
#define MAX 200010

typedef pair<int,int>  PR;

PR pa[MAX];

void initDsu(int n) {FOR(i,0,n+1) pa[i] = {i, 0};}
PR finPa(int p)
{
    if(pa[p].F == p) return pa[p];

    int par = pa[p].S;
    pa[p] = finPa( pa[p].F ); pa[p].S ^= par;

    return pa[p];
}

int mergeNode(int u,int v)
{
    PR a = finPa( u ), b = finPa( v );

    int r1 = a.F, r2 = b.F;
    int c1 = a.S, c2 = b.S;

    if(r1 == r2) return (c1 == c2);

    pa[r1].F = r2;
    pa[r1].S = (c1 == c2);

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, u, v;
    cin >> n >> m; initDsu(n);
    FOR(i,1,m)
    {
        cin >> u >> v;
        if(!mergeNode(u, v))
        {
            cout << 0 << endl;
            return 0;
        }
    }

    LL c = 0, a = 0, b = 0;
    FOR(i,1,n)
    {
        if(pa[i].S == 0) a++;
        else b++;
    }


    return 0;
}

