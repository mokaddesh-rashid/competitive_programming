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


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        LL i, j, x, y, n, m, k;

        cin >> k >> n;
        cout << "Case " << ca++ << ":\n";
        if( k == 0 )
        {
            x = n/3;
            cout << x << endl;
            n -= x;
            x = n/3;
            cout << x+x << endl;
            cout << x << endl;
        }
        else
        {
            x = n+n+n;
            cout << x/2 << endl;
            cout << n+n << endl;
            x = x/2;
            x = x*3;
            cout << x << endl;

        }

    }






    return 0;

}


