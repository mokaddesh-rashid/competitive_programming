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
#define M          998244353
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

string l, r, str;
PR dp[22][(1<<10) + 10][2];
LL muk[22];
int n, k;

PR rec(int p,int mask,int t)
{
    PR &temp = dp[p][mask][t];
    if(temp.F != -1) return temp;

    int digc = 0;

    FOR(i,0,9) if(mask & (1<<i)) digc++;

    temp = {0, 0};
    int val = str[p] - '0';
    PR ret;

    FOR(i,0,9)
    {
        if(digc == k && !( mask & (1<<i) ) ) continue;
        if(!t && i > val) continue;

        if(p == n-1) ret = {1, i};
        else
        {
            int nt = t;
            if(i < val) nt = 1;

            int newMask = mask | (1<<i);
            if(!i && !digc) newMask = 0;

            ret = rec(p + 1, newMask, nt);

            LL chao = (LL)i * muk[p]; chao %= M;
            chao = (LL) chao * ret.F; chao %= M;

            ret.S +=  chao; ret.S %= M;
        }

        temp.F += ret.F; temp.F %= M;
        temp.S += ret.S; temp.S %= M;

    }

    return temp;
}

LL getVal(string L)
{
    str = L;
    n = str.size();
    REV(i,n-1,0)
    {
        if(n - 1 == i) muk[i] = 1;
        else muk[i] = (LL)muk[i + 1] * 10;
    }

    mem(dp, -1);
    return rec(0, 0, 0).S;
}

string getString(LL v)
{
    v--;
    string str = "";
    char ch;

    if(!v) return "0";
    else
    {
        while(v)
        {
            str += ((v % 10) + '0');
            v /= 10;
        }
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    LL x, y;

    cin >> x >> r >> k; l = getString( x );

    x = getVal( l );
    y = getVal( r );

    y += (M - x); y %= M;

    cout << y << endl;

    return 0;
}
