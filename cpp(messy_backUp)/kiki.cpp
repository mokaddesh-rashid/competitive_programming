#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define LL          unsigned long long
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
typedef pair<int,int> PR;

map<int, int> mopa;
map<LL, int> hasho;
int valueId(int v)
{
    if(mopa[v] != 0) return mopa[v];
    else return mopa[v] = mopa.size();
}
int hashId(LL v)
{
    if(hasho[v] != 0) return hasho[v];
    else return hasho[v] = hasho.size();
}

vector<int> mat[MAX], poi[MAX];
int hid[MAX], col[MAX], fin[MAX];
vector< pair<PR,int> > XY;
vector<PR> LR;


int main()
{
    ///inf;
    int n, q, s, u, v, z;
    LL hh, ba;

    sff(n, q);///cin >> n >> q;
    FOR(i,1,n)
    {
        sf(s);///cin >> s;
        mat[i].resize( s );
        FOR(j,0,s-1)
        {
            sf(mat[i][j]);//cin >> mat[i][j];
            mat[i][j] = valueId( mat[i][j] );
        }

        sort(mat[i].begin(), mat[i].end());

        hh = 0; ba = 1;
        for(int j = 0; j < s; j++)
        {
            hh += (ba * mat[i][j]);
            ba *= 304729;
        }
        hh = hashId( hh );
        hid[i] = hh;
        poi[ hh ].PB( i );
    }

    XY.resize( q ); LR.resize( q );
    int x, y, l, r;

    FOR(oo,0,q-1)
    {
        sff(x, y); sff(l, r);///cin >> x >> y >> l >> r;
        if(mat[x].size() < mat[y].size()) swap(x, y);
        XY[oo] = MP( MP(x, y), oo );
        LR[oo] = MP(l, r);
    }
    sort(XY.begin(), XY.end());

    FOR(p,0,q-1)
    {
        x = XY[p].F.F; y = XY[p].F.S; z = XY[p].S;

        if(!p || XY[p - 1].F.F != x)
        {
            for(auto v : mat[x])
                col[v] = x;
        }

        if(p && XY[p - 1].F == XY[p].F) {}
        else
        {
            hh = 0; ba = 1;
            for(auto v : mat[y])
            {
                if(col[v] == x)
                {
                    hh += (ba * v);
                    ba *= 304729;
                }
            }
        }
        ///cout << "OK" << hh << endl;
        if(hasho.find( hh ) != hasho.end())
        {
            int ss = hashId( hh );

            l = LR[z].F; r = LR[z].S;
            l = upper_bound(poi[ss].begin(), poi[ss].end(), l - 1) - poi[ss].begin();
            r = upper_bound(poi[ss].begin(), poi[ss].end(), r) - poi[ss].begin();

            fin[z] = r - l;
        }

    }

    FOR(i,0,q-1) printf("%d\n", fin[i]);

    return 0;
}
