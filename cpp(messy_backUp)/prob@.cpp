#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define sfff(a,b,c)    scanf("%lld %lld %lld", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

LL block, blockId[MAX], up[MAX], prin[MAX];
LL n, q;
vector<PR> mat[MAX];
PR ara[MAX];

int main()
{
    ///ios::sync_with_stdio(false);
    inf;
    outf;
    LL tc;

    sf(tc);

    FOR(tt,1,tc)
    {
        LL n, q, x, y, ty, vOv;

        sff(n, q);
        block = 0;vOv = sqrt( n ); vOv++;
        ///cout << vOv << endl;

        FOR(i,0,n-1)
        {
            if(i%vOv == 0) block++;
            blockId[i] = block;
        }
        FOR(i,0,block + 1)
        {
            up[i] = 0;
            mat[i].clear();
        }

        FOR(i,0,n-1) sf(ara[i].F) , ara[i].S = i;
        sort(ara, ara + n);

        FOR(i,0,n-1)
        {
            LL p = blockId[i];
            mat[p].PB( ara[i] );
        }

        FOR(pp,1,q)
        {
           sfff(ty, x, y);

           if(ty == 1)
            {
                FOR(i,0,block)
                {
                    LL sz = mat[i].size();
                    if(sz && mat[i][sz - 1].F + up[i] <= x)
                    {
                        up[i] -= y;
                    }
                    else if(sz && mat[i][0].F + up[i] <= x)
                    {
                        for(LL po = 0; po < (LL)mat[i].size(); po++)
                        {
                            if(mat[i][po].F + up[i] > x) continue;
                            mat[i][po].F -= y;
                        }

                        if(y < 0) sort(mat[i].begin(), mat[i].end());
                    }

                }
            }
            else
            {
                FOR(i,0,block)
                {
                    LL sz = mat[i].size();
                    if(sz && mat[i][0].F + up[i] >= x) up[i] += y;
                    else if(sz && mat[i][sz - 1].F + up[i] >= x)
                    {
                         for(LL po = 0; po < (LL)mat[i].size(); po++)
                        {
                            if(mat[i][po].F + up[i] < x) continue;
                            mat[i][po].F += y;
                        }
                        if(y < 0) sort(mat[i].begin(), mat[i].end());
                    }

                }

            }

        }


        FOR(ok,0,block)
        {
            for(auto cp : mat[ok])
            {
                prin[cp.S] = cp.F + up[ok];
            }
        }

        FOR(i,0,n-1)
        {
             pf("%lld",prin[i]);
             if(i != n-1)  pf(" ");
        }
        pf("\n");
    }


    return 0;
}
