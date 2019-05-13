#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


LL mat[1010][1010], nf, ar[1010], tim[1010], n, x, c, m, nob, vis[1010], stk[1010], top;

LL chk()
{
    LL a, b = 0, d;

    for(int i=0; i<nob; i++ )
    {
        a = ar[i];
        for(int j=0; j<nob; j++ )
        {
            d = ar[j];
            if( mat[a][d] == 0 && d != a )
                return 0;
        }
    }

        return 1;

}

struct node
{
    LL v, pa, l;
}dfa[100010];
vector<int> maat[1001];

void dfs( LL p )
{
    LL x, y, z;


    if( dfa[p].v == 0 )
    {

        dfa[p].v = 1;
        for(LL i=0; i<maat[p].size(); i++ )
        {
            if( vis[p] == 0 )
                   stk[++top] = p, vis[p] = 1;
            LL x = maat[p][i];
            if( dfa[x].v == 0 )
            {
                dfa[x].l = dfa[p].l;
                dfa[x].pa = p;
                dfs(x);
            }
            else if( mat[p][x] == 1 && c == 0 )
            {
                memset( tim, 0, sizeof(tim));
                int t = top;
                nob = 0;
                while( t >= 0 )
                {
                   cout << stk[t] << ' ';
                   ar[nob] = stk[t];
                   tim[stk[t]] = 1;
                   t--;
                   nob++;
                   if( stk[t] == x )
                   {
                        cout << stk[t] << ' ';
                        ar[nob] = stk[t];
                        tim[stk[t]] = 1;
                        t--;
                        nob++;
                   }
                }
                cout << endl;
                x = chk();
                nob = 0;
//                for(int j=1; j<=n; j++ )
//                    if( tim[j] == 0 ) cout << j << ' ';
//                cout << endl;
                for(int j=1; j<=n; j++ )
                    if( tim[j] == 0 ) ar[nob] = j, nob++;
                y = chk();
                c = max(min( x , y ), c);

            }
        }
        if( vis[p] != 0 )
            vis[p] = 0, top--;
    }
}




int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int ca;
    cin >> ca;

    while( ca-- )
    {
        memset( mat, 0, sizeof(mat) );
        memset( vis, 0, sizeof(vis) );
        memset( dfa, 0, sizeof(dfa) );
        LL i, j, x, y, a, b ;
        c = 0;
        cin >> n >> m;
        for( i=1; i<=n; i++ )
            maat[i].clear();
        for( i=0; i<m; i++ )
             {
                 cin >> a >> b;
                 mat[a][b]++;
                 mat[b][a]++;
                 maat[a].push_back(b);
                 maat[b].push_back(a);
             }
        top = -1;
        dfs(1);
        if( c == 1 )
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;

}



