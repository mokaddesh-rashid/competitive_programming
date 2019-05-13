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
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> pr;


//set<LL>::iterator ii;

struct node
{
    LL v, pa, l;
}bfa[200];

vector<LL> mat[200];
LL que[200], h, r, n, m;

void bfs( LL p )
{
    bfa[p].l = 0;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    que[r] = 1;
    r++;
    while( h != r )
    {
        //cout << p << " = ";
        for(LL i=0; i<mat[p].size(); i++ )
        {
            LL x = mat[p][i];
            if( bfa[x].v == 0 )
            {
                //cout << x << ' ';
                bfa[x].l = bfa[p].l+1;
                bfa[x].pa = p;
                bfa[x].v = 1;
                que[r] = x;
                r++;
            }
        }
        //cout << endl;
        h++;
        p = que[h];
    }

}

LL con[20][20], dir[100][2];
LL cnt[200];

void rec( LL x, LL y, LL z , LL k )
{
    //cout << x << ' ' << y << ' ' << z << ' ' << k << endl;
    if( x < 0 || y < 0 || x >= n || y >= m ) return ;
    if( z == k )
    {
        con[x][y]++;
        return;
    }
    for(LL i=0; i<8; i++ )
        rec( x+dir[i][0], y+dir[i][1], z+1 , k);

    return;
}

void cret_dir()
{
   ///(x+1, y+2), (x+1, y-2), (x+2, y+1), (x+2, y-1), (x-1, y+2), (x-1, y-2), (x-2, y+1), (x-2, y-1)
   dir[0][0] = 1, dir[0][1] = 2;
   dir[1][0] = 1, dir[1][1] = -2;
   dir[2][0] = 2, dir[2][1] = 1;
   dir[3][0] = 2, dir[3][1] = -1;
   dir[4][0] = -1, dir[4][1] = 2;
   dir[5][0] = -1, dir[5][1] = -2;
   dir[6][0] = -2, dir[6][1] = 1;
   dir[7][0] = -2, dir[7][1] = -1;
}

void edge( LL x )
{
    LL k = 0, y;

    for(LL i=0; i<n; i++ )
      for(LL j=0; j<m; j++ , k++)
        {
           if( con[i][j] != 0 )
           {
               y = k;
               //cout << x << ' ' << y << endl;
               mat[x].push_back( y );
               mat[y].push_back( x );

           }
        }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    LL t , ca = 1;
    cret_dir();

   cin >> t;

   while(t--)
    {
        memset( cnt, 0,sizeof(cnt) );
        LL i, j, x, y, k = 0, a, b, c, d = maxx;
        string str[12];

        cin >> n >> m;

        for( i=0; i<n; i++ )
            cin >> str[i];
        for( i=0; i<110; i++ )
            mat[i].clear();

        for( i=0; i<n; i++ )
            for( j=0; j<m; j++ , k++)
        {
               memset( con, 0, sizeof(con) );
               x = str[i][j]-'0';
               if(str[i][j] != '.' ) cnt[k] = x;
               rec( i, j, 0, 1 );
               //cout << endl << k  << ' ' <<  x << endl << endl;
               //for( x = 0; x<n; x++ )
               {
                  // for( y=0; y<m; y++ )
                    //cout << con[x][y] << ' ';

                   //cout << endl;
               }
               edge(k);

        }

        i = 0;
        while( i < k )
        {
            memset( bfa, 0, sizeof(bfa) );
            h = r = a = c = 0;
            bfs(i);
            for( j=0; j<k; j++ )
            {
                if( i != j && cnt[j] != 0 && bfa[j].l == 0 ) a = 1;
                if( cnt[j] != 0 )
                {
                    c += (bfa[j].l/cnt[j]);
                    if( bfa[j].l % cnt[j] ) c++;
                }
            }
            if( a == 0 ) d = min( d, c);
            i++;
        }

        cout << "Case " << ca++ << ": ";
        if( d == maxx ) cout << -1 << endl;
        else cout << d << endl;

    }

    return 0;

}



