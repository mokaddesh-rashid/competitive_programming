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
typedef pair<int,int> pr;
typedef pair<double,int> dr;

pr ar[MAX], in[MAX];
dr val[MAX];
int n, p;

double somoy(int ap,int bp,int av,int bv)
{
    double dis = abs(ap - bp), spd = av + bv;
    double tim = dis/spd;
    cout << dis << ' ' << spd << endl;
    return tim;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> ar[i].F >> ar[i].S;
    }

    FOR(i,0,n-1)
    {
        FOR(j,i + 1,n-1)
        {
            val[i].F = somoy(ar[i].F, ar[j].F, ar[i].S, ar[j].S);
            cout << val[i].F << endl;
            val[i].S = p;
            in[p].F = i; in[p].S = j;
            p++;
        }
    }

    sort(val, val + p);

    FOR(i,0,p-1)
    {
        ///cout << val[i].F << ' ';
    }

    return 0;
}

