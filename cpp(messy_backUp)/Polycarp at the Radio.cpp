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
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;

LL ar[100001], n, m, cnt[100000], use[100000];

int chk( )
{
    for( int i=1; i<=m; i++ )
    {
        if( cnt[i] > 0 ) return i;
    }

    return -1;
}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, a, b, c;

    c = 0;

    cin >> n >> m ;

    for( i=0; i<n; i++ )
    {
        cin >> ar[i];
    }

    a = n/m;

    cout << a << ' ';

    for( i=1; i<=m; i++ )
        cnt[i] = a;

    for( i=0; i<n; i++ )
    {
       x = ar[i];
       if( x <= 2000 && cnt[x] > 0 ) cnt[x]--, use[i] = 1;

    }

    for( i=0; i<n; i++ )
    {
        if( use[i] == 0 )
        {
            x = chk();
            if( x != -1 )
            {
                c++;
                ar[i] = x;
                cnt[x]--;
            }
        }
    }
    cout << c << endl;
    for( i=0; i<n; i++ )
    {
        cout << ar[i] << ' ';
    }


    return 0;

}


