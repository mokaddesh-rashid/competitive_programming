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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 200036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL n;
string str[100001], rev[100001];
LL ar[100010];


LL dp[100010][3], ck = 0;

LL rec( LL x, LL y, LL z )
{
    //cout << x << y << endl;
    LL a, temp = maxx;
    if( x >= n-1 )
       {

           ck = min( ck, z );
           return 0;
       }

    if ( str[x] < str[x+1] )
        temp =  rec( x+1, 0 , z);

    if( rev[x] < str[x+1] )
        temp =  min( temp, rec( x+1, 1 , z+ar[x] ));

    if( str[x] < rev[x+1] )
        temp =  min( temp, rec( x+1, 1 ,z+ar[x+1] ));


     dp[x][y] = temp;
    return dp[x][y];


}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( dp, -1, sizeof(dp) );
    LL i, j, x = 0, y, m, a;

    cin >> n ;

    for( i=0; i<n; i++ )
        cin >> ar[i];

    for( i=0; i<n; i++ )
        {
            cin >> str[i];
            rev[i] = str[i];
            reverse( rev[i].begin(), rev[i].end() );
            //cout << rev[i] << endl;
        }
    //cout << chk( "aaa", "aaaa" );
    ck = maxx;
    x =  rec( 0 , 0 , 0);

    if( ck == maxx )
        cout << -1;
    else
        cout << ck;

    return 0;

}


