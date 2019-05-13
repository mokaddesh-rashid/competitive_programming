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
typedef pair<LL,LL> PR;


LL sparceT[17][MAX], lev[MAX], val[MAX], sumT[17][MAX], L, S;
vector<int> mat[MAX];

void dfs(int p)
{
    for(auto x : mat[p])
    {
        lev[x] = lev[p] + 1;
        sparceT[0][x] = p; sumT[0][x] = val[p];

        dfs(x);
    }

    return;
}

void make_sparceT(LL n)
{
    FOR(i,1,16)
        FOR(j,1,n)
        {
            LL x = sparceT[i - 1][j];
            if(x == -1) continue;
            sparceT[i][j] = sparceT[i - 1][x];
            sumT[i][j] = sumT[i - 1][j] + sumT[i - 1][x];
        }
}

LL canGo(LL u,LL val,LL jump)
{
    if(jump == -1) return u;

    LL to = sparceT[jump][u];
    LL dorkar = sumT[jump][u];

    if(to == -1 ||  dorkar > val) return canGo(u, val, jump - 1);
    else return canGo(to, val - dorkar, jump);

}

int prin = 0, pa[MAX], done[MAX];

void initDsu(){FOR(i,0,MAX-1) pa[i] = i, done[i] = 1;}
int finPa(int p){return pa[p] == p ? p : pa[p] = finPa( pa[p] );}

void rec(int p)
{
    for(auto x : mat[p]) rec(x);

    if(done[p])
    {
       /// cout << "cuurent at " << p << endl;
        prin++;

        int u = p, v;
        LL c  = 0;

        while(lev[p] - lev[u] < L && c + val[u] <= S)
        {
           /// cout << "clean " << u << endl;
            done[u] = 0; c += val[u];
            v = sparceT[0][u];

            if(v == -1) break;
            else
            {
                int r1 = finPa( u ), r2 = finPa( v );
                if(r1 != r2) pa[r1] = r2;
            }

            u = finPa( u );
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    LL n, u, v, q;

    cin >> n >> L >> S;
    FOR(i,1,n)
    {
        cin >> val[i];
        if(val[i] > S)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    FOR(i,2,n)
    {
        cin >> u;
        mat[u].PB( i );
        ///cout << u << ' ' << i << endl;
    }

    mem(sparceT, -1);
    dfs(1);
    make_sparceT( n );

    initDsu();
    rec(1);
    cout << prin << endl;

    return 0;
}
