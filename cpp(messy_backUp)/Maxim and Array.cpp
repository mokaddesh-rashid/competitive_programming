#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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

/*dir array
//8 moves
LL fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
LL fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
LL fx[]={+1,-1,+0,+0};
LL fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<LL>::iterator ii;

pr mp[200020];
LL ar[200010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, a = 0, b, c, d, e, f, g, k;

    cin >> n >> k >> x ;

    for( i=0; i<n; i++ )
    {
        cin >> a;
        ar[i] = a;
        mp[i].first = a;
        mp[i].second = i;

    }

    for( i=0; i<n; i++ )
    {
        b = mp[i].first;
        if( a == 0 )
        {
            e = 0;
            if( x > 0 )
            {
                c = b/x;
                if( b%x ) c--, d = b%x, e = 1;

                if( c == k )
                {
                   if( e == 1 )
                   {
                       mp[i].first = d-x;
                       a = 1;
                   }
                   else
                   {
                       mp[i].first = 0;

                   }
                }
                else if( c < k )
                {
                    if( e == 1 )
                   {
                       mp[i].first = d-x;
                       a = 1;
                   }
                   else
                   {
                       mp[i].first = x*-1;
                       c++;
                       a = 1;

                   }
                }
                else
                {
                    mp[i].first = mp[i].first - ( x*k );
                }
                k -= c;

            }
        }
        else if( k > 0 )
        {
            mp[i].first += x;
            k--;
        }
    }

    if( k > 0 )
        mp[i].first += (k*x);

    for( i=0; i<n; i++ )
    {
        ar[mp[i].first] = mp[i].second;
    }

    for( i=0; i<n; i++ )
        cout << ar[i] << ' ';







    return 0;

}


