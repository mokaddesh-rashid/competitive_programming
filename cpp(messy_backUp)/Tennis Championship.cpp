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
#define maxx          (long long) 2000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define FF first
#define SS second
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

LL ar[1000100];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m;

    cin >> n;

    ar[0] = 0; ar[1] = 2; ar[2] = 3; ar[3] = 5; ar[4] = 8;
    i = 5;

    while( ar[i-1]+ar[i-2] <= maxx )
    {
        ar[i] = ar[i-1] + ar[i-2];
        //cout << ar[i] << ' ';
        i++;
    }

    x = lower_bound( ar, ar+i, n ) - ar;

    //cout << ar[x] << endl;
    if( ar[x] > n ) x--;

    cout << x;

    return 0;

}


