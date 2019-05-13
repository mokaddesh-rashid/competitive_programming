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
#define M             (long long)100000000000000
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1510
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,int> PR;

int ara[MAX];

int revPair(LL v)
{
    mem(ara, 0);
    int p = 0;

    while( v )
    {
        ara[p] = v % 10;
        p++; v /= 10;
    }
    reverse(ara, ara + 15);

}

int dp[16][16][10][2][110];
int col[16][16][10][2][110], cc;

LL rec(int p,int bao,int val,int t,int ret)
{
    ///cout << p << ' ' << bao << ' ' << val << ' ' << t << endl;
    if(p == 15) return ret;

    int &temp = dp[p][bao][val][t][ret];
    if(temp != -1 && t) return temp;
    if(col[p][bao][val][t][ret] == cc) return temp;

    temp = 0;
    int l = ara[p]; if(t) l = 9;

    for(int i = 0; i <= l; i++)
    {
        int newbao = bao + (i < val), newT = 1, newRet = ret;
        if(i == ara[p]) newT = t;
        if(i == val) newRet += bao;

        temp += rec(p + 1, newbao, val, newT, newRet);

    }

    col[p][bao][val][t][ret] = cc;
    return temp;
}

LL getVal(LL v)
{
    int i;
    LL prin = 0;
    revPair( v );

    for(i = 0; i <= 14; i++)
        if(ara[i]) break;
    for(int j = i; j <= 14; j++)
    {
        int l = 9;
        if(i == j) l = ara[i];

        for(int k = 1; k <= l; k++)
        {
            for(int d = 0; d <= 9; d++)
            {
                cc++;
                if(k == l && i == j) prin += rec(j + 1, (k < d), d, 0, 0);
                else prin += rec(j + 1, (k < d), d, 1, 0);
            }
        }
    }
    return prin;
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    LL prin = 0, l, r;
    mem(dp, -1);
    ///cout << getVal(1) << ' ' << getVal( 100 ) << endl;

    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
        l = rand() % M; r = rand() % M;
        if(l > r) swap(l, r);

        prin += getVal( r );
        prin -= getVal( l - 1 );

        cout << prin << endl;
        prin = 0;
    }


    return 0;
}
