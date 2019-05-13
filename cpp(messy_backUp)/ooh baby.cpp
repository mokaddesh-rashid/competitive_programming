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
#define MAX 300010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

LL dp[MAX][2];
int ara[MAX], n;

int bitcount(LL v)
{
    int ret = 0;
    FOR(i,0,60) if(v & (LL)1<<i) ret++;
    return ret;
}

LL rec(int p,int t)
{
    if(p == n) return 0;

    LL &temp = dp[p][t];
    if(temp != -1) return temp;

    temp = 0; t += ara[p]; t %= 2;
    temp = rec(p + 1, t);
    if(!t) temp++;

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    LL prin = 0, v;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> v;
        ara[i] = bitcount( v );
        //cout << ara[i] << ' ';
    }
    //cout << endl;

    mem(dp, -1);
    FOR(i,0,n-1)
    {
        int v = 0, mo = 0;
        FOR(j,i,n-1)
        {
            v += ara[j];
            mo = max(mo, ara[j]);
            if( !(v%2) && v - mo >= mo) prin++;

            if(v - mo >= 64)
            {
                v %= 2;
                prin += rec(j + 1, v);
                break;
            }
        }
    }
    cout << prin << endl;

    return 0;
}

