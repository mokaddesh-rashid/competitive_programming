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

        int i, j, x, y, n, m = 0, p = 0;
        string str[110];

        cin >> n;

        for( i=0; i<n; i++ )
        {
            cin >> str[i];
        }

        for( i=0; i<n; i++ )
        {
            x = 0;
            for( j=0; j<n; j++ )
            {
                if( str[j] == str[i] )
                    x++;
            }
            if( x > m ) m = x, p = i;
        }
        cout << "Case " << ca++ << ": ";
        cout << str[p] << endl;

    }
    return 0;

}


