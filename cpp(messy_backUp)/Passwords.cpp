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

int ar[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, k, v, a, b, c, d, low, up;
    string str;

    cin >> n >> k;

    for( i=0; i<n; i++ )
    {
        cin >> str;
        x = str.size();
        ar[i] = x;
    }

    sort( ar, ar+n );

    cin >> str;

    v = str.size();
    b = a = 0;

    for( i=0; i<n; i++ )
    {
        if( ar[i] == v )
        {
            a++;
            break;
        }
        else
        {
            a++;
            b++;
            if( b == k ) a += 5, b = 0;
        }
    }

    cout << a << ' ';

    b = a = 0;

    for( i=0; i<n; i++ )
    {
        if( ar[i] == v && ar[i+1] != v )
        {
            a++;
            break;
        }
        else
        {
            a++;
            b++;
            if( b == k ) a += 5, b = 0;
        }
    }

    cout << a << ' ';

    return 0;

}


