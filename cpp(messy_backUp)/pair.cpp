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

int vis[6000010], cnt[6000010], pos[600060];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c, k;
    c = 0;
    cin >> n >> k;

    for( i=0; i<k; i++ )
        cin >> a, vis[a]++, pos[a] = i+1;
    //for( i=1; i<=n; i++ )
        //cout << i << ' ' << vis[i] << endl;
    for( i=1; i<=n; i++ )
    {
       if( vis[i] != 0 && cnt[i] == 0 )
      {
          //cout << i << endl;
          for( j=i+i; j<=n; j += i )
       {
          cnt[j]++;
          if( vis[j] != 0 )
                {
                    //cout << i << ' ' << j << endl;
                    cout << pos[i] << ' ' << pos[j] << endl, c = 1;
                    break;
                }

       }
       if( c == 1 )
        break;
      }

    }

    if( c == 0 )
        cout << "0 0";



    return 0;

}


