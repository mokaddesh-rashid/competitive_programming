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

struct node
{
    int a, b;
}ar[110];

vector<int>mat[10001];
int cnt[1010];

void input( int n )
{
    int a, b;
    for(int i=0; i<n; i++ )
    {
        cin >> a >> b;
        ar[i].a = a, ar[i].b = b;
        for(int j=a; j<b; j++ )
            mat[j].push_back(i);
    }
}

int avail( int p , int mid)
{
    int l = 100000, re = -1, x;

    for( int i=0; i<mat[p].size(); i++ )
    {
        x = mat[p][i];
        if( cnt[x] < mid && ar[x].b < l )
            re = x, l = ar[x].b;
    }

    return re;
}
int chk( int mid , int n )
{
    memset( cnt, 0, sizeof(cnt) );
    int x;
    for(int i=0; i<10001; i++ )
    {
        x = avail( i, mid );
        //cout << i << ' ' << x << endl;
        if( x != -1 ) cnt[x]++;
    }
    //for(int i=0; i<n; i++ )
        //cout << cnt[i] << ' ';
    for(int i=0; i<n; i++ )
        if( cnt[i] < mid )
           return 0;

    return 1;

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, st, en, mid, c = 0;

    cin >> n;

    input(n);

    st = 0;
    en = 10000;

    while( st <= en )
    {
        mid = (st+en)/2;
        x = chk( mid, n );

        if( x == 0 )
            en = mid-1;
        else
            st = mid+1, c = max( c, mid );

    }

    cout << c*n;

    return 0;

}
