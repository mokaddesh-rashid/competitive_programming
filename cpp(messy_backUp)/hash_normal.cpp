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
#define Mo          1000000000
#define M1          1000000007
#define M2          100000007
#define B1          29
#define B2          31
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 300010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;


LL mul(LL b,LL p,LL MOD)
{
    if(p == 0) return 0;

    LL ret = mul(b, p/2, MOD);
    ret += ret; ret %= MOD;
    if(p%2) ret += b;

    return ret % MOD;
}

LL hasho(string str)
{
    LL MOD = (LL)100000000000007;
    LL n = str.size(), base = 311, p1 = 1, hashx = 0, a;

    FOR(i,0,n-1)
    {
       a = str[i]; a++;
       hashx += mul(p1, a, MOD); hashx %= MOD;
       p1 *= base; p1 %= MOD;
    }

    return hashx;
}

set<LL>sota;

int main()
{
    ios::sync_with_stdio(false);


    FOR(i,0,100)
    {
        string str;

        cin>>str;
        LL x = hasho(str);
        if(sota.find(x) != sota.end()) cout<<"ase"<<NL;
        else cout<<"Nai"<<NL;
        sota.insert(x);
    }
    return 0;
}
