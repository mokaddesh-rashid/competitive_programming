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
#define MAX 20000000
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

LL ret(LL a,LL b,LL w)
{
    LL h = a/w;
    LL ex = a%w;

    if(ex)
    {
        if(ex + b == w) return 2*(h + 1 + w);
        else return -1;
    }
    else
    {
        ///cout << h + b/w << ' ' << w << endl;
        if(b%w == 0) return 2*(h + b/w + w);
        else return -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;
    LL a, b, prin;

    cin >> a >> b; prin = -1;
    FOR(i,1,1)
    {
        LL ok = ret(a, b, i);
        if(ok != -1)
        {
            if(prin == -1) prin = ok;
            else prin = min(prin, ok);
        }
        ok = ret(b, a, i);
        if(ok != -1)
        {
            if(prin == -1) prin = ok;
            else prin = min(prin, ok);
        }
    }
    cout << prin << endl;

    return 0;
}
