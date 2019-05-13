#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
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
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

string str;
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, k, a, b, cnt = 0, c, z;
    char ch = 'p';
    x = y = z = 0;
    cin >> n >> k >> a >> b ;

    if( a > b )
    while(a>b)
    {
        if( a > b && x < k ) str += 'G', x++, a--;
        else if( b > 0) str += 'B', x = 0, b--;
        else break;
    }
    else
    while(a<b)
    {
        if( a < b && x < k ) str += 'B', x++, b--;
        else if( a > 0 )str += 'G', x = 0, a--;
        else break;
       // cout << a << ' ' << b << ' ' << x << endl;
    }

    z = str.size()-1;
    if( str[z] == 'G' )
    while( a == b )
    {
        if( b > 0 ) str += 'B', b--;
        if( a > 0 ) str += 'G', a--;
        if( a == 0 || b == 0 ) break;
    }
    else
    {
       while( a == b )
        {
            if( a > 0 ) str += 'G', a--;
            if( b > 0 ) str += 'B', b--;
            if( a == 0 || b == 0 ) break;
        }
    }
    if(str.size()<n) cout << "NO";
    else FOR(i,0,n-1) cout << str[i];
    return 0;

}


