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
#define PB push_back
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

vector<int> mat[1001];
int ar[10001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a = 0;

    cin >> n >> m ;

   for( i=0; i<m; i++ )
   {
       cin >> x >> y;
       mat[x].PB( y );
   }

   for( i=0; i<n; i++ )
   {
       cin >> x;
       ar[x] = i+1;
   }

   for( i=1; i<=n; i++ )
   {
       for( j=0; j<mat[i].size(); j++ )
       {
           x = mat[i][j];
           if( ar[i] > ar[x] ) a = 1;
       }
   }

   if( a == 1 ) cout << "NO";
   else cout << "YES";
    return 0;

}

