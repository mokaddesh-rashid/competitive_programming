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
typedef pair<int,int> p_i;


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t;
    cin >> t;

    while(t--)
    {

        LL i, j, x, y, n, m, a = 0, b, c ;

        cin >> n >> b >> m ;

        while( n > 0 )
        {
            if( n%2 ) x = (n+1)/2;
            else x = n/2;
            //cout << m << ' ' << x << endl;
            a += (m*x);
            a += b;
            m += m;
            n = n-x;
        }
         a -= b;
        cout << a << endl;
    }


    return 0;

}


