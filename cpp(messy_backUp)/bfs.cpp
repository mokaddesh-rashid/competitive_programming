
#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

vector <int> mat[100001], cost[100001];
struct info
{
    int v, l, pa, cn, dis, chk;
}lar[100001]; // array of info about input

int que[100001], hd, re, iv, n;

void bfs( int p )
{
    lar[p].l = 1;
    lar[p].pa = -1;
    lar[p].cn = 1;
    lar[p].dis = 0;
    lar[p].chk = 1;
    que[re] = p;
    re++;
    int t = 2;
    while( hd != re )
    {
        //cout << p << " = ";
        for(int i=1; i<=mat[p][0]; i++ )
        {
            int x = mat[p][i];

            if( lar[x].cn == 0 )
            {
                //cout << x << '(' << lar[p].l+1 << ')' << ' ';
                lar[x].l = lar[p].l+1;
                lar[x].dis = max( 0, lar[p].dis + cost[p][i] );
                lar[x].pa = p;
                lar[x].cn = 1;
                que[re] = x;
                re++;

                if( lar[p].chk == 0 || ( lar[x].dis > lar[x].v ) )
                    lar[x].chk = 0;
                else
                    lar[x].chk = 1;

                if( lar[x].chk == 0 )
                    iv++;


            }

        }
        cout << endl;
        hd++;
        p = que[hd];
    }
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y,  m, z;

    cin >> n ;

    for( i=1; i<=n; i++ )
    {
        mat[i].clear( );
        mat[i].push_back(0);
        cost[i].push_back(0);
       // cin >> lar[i].v;
    }


    for( i=1; i<n; i++ )
    {
       // x = i+1;
        cin >> x >> y;// >> z;
        mat[x].push_back(y);
        mat[y].push_back(x);
        //cost[x].push_back(z);
        //cost[y].push_back(z);
        mat[x][0] = mat[x][0]+1;
        mat[y][0] = mat[y][0]+1;
    }

    bfs(1);

    cout << iv;



    return 0;

}


