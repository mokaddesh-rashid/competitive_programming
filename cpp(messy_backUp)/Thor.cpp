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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int cnt[300030], val[300030], ar[300020], tt[300030], cm[300030];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j = 1, x = 0, y, n, m, l = 1, u = 0, a, b, c, d;

    cin >> n >> m ;

    for( i=1; i<=m; i++ )
    {
        cin >> a;

        if( a == 1 )
        {
            cin >> b;
            ar[j] = b;
            cm[j] = val[b]+1;
            //cout << cm[j]
            j++;
            //tt[b] = i+1;
            cnt[b]++;
            val[b]++;
            x++;
        }
        else if( a == 2 )
        {
            cin >> b;
            tt[b] = val[b];
            x -= cnt[b];
            cnt[b] = 0;
        }
        else
        {
            cin >> b;
            //cout << l << ' ' << b << endl << endl;
            while( l <= b )
            {
                //cout << l << ' ' << ar[l] << ' ' << cnt[ar[l]] << ' ' << cm[l] << ' ' << tt[ar[l]] << endl;
                if( cnt[ar[l]] > 0 &&  cm[l] > tt[ar[l]] )
                {

                    x--;
                    cnt[ar[l]]--;
                }
                l++;
            }
            //l--;
        }

        cout << x << endl;
    }



    return 0;

}

