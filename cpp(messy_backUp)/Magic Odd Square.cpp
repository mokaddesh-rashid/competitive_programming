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


//set<int>::iterator ii;

int e , o, mat[100][100];


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    e = 2;
    o = 1;
    int i, j, x, y, n, m, c = 1, a, b, d;

    cin >> n;

    x = n*n;
    x = x/2+1;
    y = n/2+1;
    a = y;

    for( i=1; i<=y; i++ )
    {
        b = a-1;
        d = c+2;

        while( c-- )
        {
            //cout << o << '(' << a << ')' << ' ';
            mat[i][a] = o;
            o += 2;
            a++;
        }
        a = b;
        c = d;
        //cout << endl;
    }

    a = 2;
    c = n-2;
    for( i=y+1; i<=n; i++ )
    {
        b = a+1;
        d = c-2;

        while( c-- )
        {
           // cout << o << '(' << a << ')' << ' ';
            mat[i][a] = o;
            o += 2;
            a++;
        }
        a = b;
        c = d;
        //cout << endl;
    }

    for( i=1; i<=n; i++ )
    {
        for( j=1; j<=n; j++ )
        {
            if( mat[i][j] == 0 )
            {
                cout << e << ' ';
                e += 2;
            }
            else
                cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;

}


