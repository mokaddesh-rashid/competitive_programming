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
#define MAX 5010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

deque<PR> que[MAX];
LL ara[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    LL n, k, s;

    cin >> n >> k >> s;
    FOR(i,0,n-1) cin >> ara[i];

    LL prin = -1;
    que[0].push_back( MP(0, -1) );
    FOR(i,0,n-1)
    {
        REV(lev,s-1,0)
        {
            LL l = i - k;

            while(!que[lev].empty() && que[lev].front().S < l)
            {que[lev].pop_front();}

            if(!que[lev].empty())
            {
                PR VoV = MP(que[lev].front().F + ara[i], i);

                while(!que[lev + 1].empty() && que[lev + 1].back().F <= VoV.F)
                {que[lev + 1].pop_back();}

                que[lev + 1].push_back( VoV );
                if(n - i <= k) prin = max(prin, VoV.F);
            }
        }
    }

    cout << prin << endl;
    return 0;
}

