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

PR paa[MAX];
int sz[MAX];

PR finPa(int p)
{
    if(paa[p].F == p) return paa[p];

    PR ret = finPa( paa[p].F );

    ret.S ^= paa[p].S;
    paa[p].F = ret.F;

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;
    int n;

    cin >> n;

    FOR(i,1,n) paa[i] = {i, 0}, sz[i] = 1;

    for(;;)
    {
        int a, b, c, ty;

        cin >> ty;
        if(ty == 0)
        {
            cin >> a;
            PR show = finPa( a );
            cout << show.F << ' ' << show.S << endl;
        }
        else
        {
            cin >> a >> b;

            int r1 = finPa( a ).F, r2 = finPa( b ).F;
            if(r1 == r2 && paa[a].S == paa[b].S)
            {
                cout << "ODD Baby" << endl;
            }
            else if(r1 == r2 && paa[a].S != paa[b].S)
            {
                cout << "EVEN Baby" << endl;
            }
            else
            {
                if(sz[r1] < sz[r2]) swap(r1, r2);

                paa[r2].F = r1;
                paa[r2].S = 1;
                sz[r1] += sz[r2];
            }
        }
    }

    return 0;
}

