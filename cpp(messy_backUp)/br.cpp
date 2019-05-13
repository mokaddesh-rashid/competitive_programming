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
typedef pair<int,int> PR;


LL rec(LL v,LL k,int t)
{
    if(v <= k) return v;

    if(!t) return k + rec(v - k, k, 1);
    else
    {
        LL rv = v / 10;
        return rec(v - rv, k, 0);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    ///outf;
    LL v, k, st, en, mid, prin;

    cin >> v;
    st = 1; en = v; prin = v;

    while(st <= en)
    {
        mid = (st + en)>>1;

        if(rec(v, mid, 0)*2 >= v) en = mid - 1, prin = min(mid, prin);
        else st = mid + 1;
    }
    cout << prin << endl;

    return 0;
}

