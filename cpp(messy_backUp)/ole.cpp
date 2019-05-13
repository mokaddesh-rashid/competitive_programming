#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;


vector<int> mat[MAX];
vector<PR> paInfo[MAX][25];

int lev[MAX], pa, cen, sub[MAX], tr_sz, dis[25][MAX], val[25][MAX];
int  chi[MAX][25][2], myPaChi[MAX][25][2];

void col_info(int p,int baap)
{
    if(cen)
    {
        FOR(bit,0,22)
        {
            if(!paInfo[p][bit].empty())
                myPaChi[cen][bit][ paInfo[p][bit][(int)paInfo[p][bit].size() - 1].S ]++;

            chi[cen][bit][ dis[bit][p] ]++;
        }

        FOR(bit,0,22)
            paInfo[p][bit].PB( {cen, dis[bit][p]} );
    }

    sub[p] = 1;
    for(auto x : mat[p])
    {
        if(lev[pa] < lev[x]) pa = x; ///finding parents in cen tree
        if(x == baap || lev[x]) continue;

        FOR(bit,0,22) dis[bit][x] = dis[bit][p] ^ val[bit][x];
        col_info(x, p);
        sub[p] += sub[x];

    }
}

int centroid(int p,int baap)
{
    if((sub[p]<<1) <= tr_sz) return baap;

    for(auto x : mat[p])
        if((sub[x]<<1) > tr_sz && !lev[x] && x != baap)
            return centroid(x, p);

    return p;
}

int org[MAX];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    int n, u, v, k;

    cin >> n;

    FOR(i,1,n) cin >> org[i];
    FOR(i,1,n-1)
    {
        cin >> u >> v;
        mat[u].PB( v ); mat[v].PB( u );
    }

    LL prin = 0, show = 0;
    FOR(i,1,n) show += org[i];

    FOR(bit,0,22)
        FOR(i,1,n)
        {
            if(org[i] & (1<<bit)) val[bit][i] = 1;
            else val[bit][i] = 0;
        }


    FOR(l,1,18)
    FOR(i,1,n)
    {
        if(lev[i]) continue;

        pa = 0; col_info(i, i); tr_sz = sub[i];
        cen = centroid(i, i);///pa and cen majhe edge hobe

        FOR(bit,0,22) dis[bit][cen] = 0;
        col_info(cen, cen);
        lev[cen] = lev[pa] + 1; cen = 0;
    }

    FOR(i,1,n)
    FOR(bit,0,22)
    reverse(paInfo[i][bit].begin(), paInfo[i][bit].end());
    FOR(bit,0,22)
    {
        prin = 0;
        FOR(i,1,n)
        {
            int len = k;

            FOR(j,0,(int)paInfo[i][bit].size() - 1)
            {
                PR x = paInfo[i][bit][j];
                int p = x.F, d = val[bit][p] ^ x.S;
                prin += chi[p][bit][d ^ 1];

                if(j == (int)paInfo[i][bit].size() - 1) continue; ///parents niche dr cover k

                d = val[bit][ paInfo[i][bit][j + 1].F ] ^ paInfo[i][bit][j + 1].S;
                prin -= myPaChi[p][bit][d ^ 1];

            }
        }

        show += (prin * (LL)1<<bit);
    }

    cout << ((LL)show>>1) << endl;

    return 0;
}
