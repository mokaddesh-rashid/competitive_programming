#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define F first
#define S second
#define MAX 1010

typedef pair<int,int>  PR;

PR pa[MAX];

void initDsu() {FOR(i,0,MAX-1) pa[i] = {i, 0};}
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

    return 2;
}

vector< pair<PR,PR> > useful;
pair<PR,PR> con[(MAX*MAX)>>1];
int use[(MAX*MAX)>>1];

int main()
{
    ios::sync_with_stdio(false);

    int n, u, v, m, q, l, r;

    cin >> n >> m >> q;
    FOR(i,0,m-1)
    {
        cin >> con[i].S.F >> con[i].S.S >> con[i].F.F;
        con[i].F.S = i;
    }

    sort(con, con + m);
    reverse(con, con + m);

    initDsu();
    FOR(i,0,m-1) useful.push_back( con[i] );

    FOR(oo,0,q-1)
    {
        cin >> l >> r; l--; r--;

        initDsu();
        int prin = -1;

        for(auto x : useful)
        {
            if(x.F.S < l || x.F.S > r) continue;

            if(mergeNode(x.S.F, x.S.S) == 1)
            {
                prin = x.F.F;
                break;
            }
        }

        cout << prin << endl;
    }

    return 0;
}
