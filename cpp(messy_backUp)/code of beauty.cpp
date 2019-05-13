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

int pa[MAX], sz[MAX];

int isGood(LL val)
{
    while(val > 0)
    {
        LL m = (val % 10);
        if(m != 4 && m != 7) return 0;
        val /= 10;
    }
    return 1;
}

int finPa(int p)
{
    return (pa[p] == p) ? p : (pa[p] = finPa( pa[p] ));
}

int main()
{
    ios::sync_with_stdio(false);
   // inf;
    //outf;

    int n;
    LL a, b, c;

    cin >> n;
    FOR(i,1,n) sz[i] = 1, pa[i] = i;
    FOR(i,1,n-1)
    {
        cin >> a >> b >> c;
        c = isGood( c );
        if(!c)
        {
            int r1 = finPa(a), r2 = finPa(b);
            //cout << r1 << ' ' << r2 << endl;
            if(r1 == r2) continue;
            sz[r1] += sz[r2];
            pa[r2] = r1;
        }
    }

    LL prin = 0;
    FOR(i,1,n)
    {
        LL a = n - sz[finPa(i)];
        ///cout << sz[a] << endl;
        prin += (a * (a - 1));
    }

    cout << prin << endl;

    return 0;
}

