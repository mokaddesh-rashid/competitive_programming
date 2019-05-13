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

string str;
int  us[200010];

struct info
{
   LL sum, val, lazy;

}tree[4*MAX];
LL ar[200010];

void init(LL idx, LL b, LL e )
{

    if( b == e )
    {
        cnd.sum = ar[b];
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    cnd.sum =  tree[lnd].sum + tree[rnd].sum ;

    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum += ((e-b+1) * v);
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt);
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, k, c = 0;

    cin >> n >> a >> b >> k ;

    cin >> str;

    for( i=0; i<n; i++)
    {
        if( str[i] == '0' ) ar[i+1] = 0;
        else ar[i+1] = 1;

        us[i+1] = ar[i+1];
    }

    init( 1, 1, n );

    for( i=1; i+b-1<=n; i++ )
    {
        x = query( 1, 1, n, i, i+b-1 );

        if( x == 0 )
        {
            ar[i+b-1] = 1;
            update( 1, 1, n, i+b-1, i+b-1, 1 );
        }
    }

    c = 0;
    for( i=1; i<=n; i++ )
    {
        if( ar[i] != us[i] ) c++;
    }

    cout << c-a+1 << endl;
    c = c-a+1;

    for( i=1; i<=n; i++ )
    {
        if( ar[i] != us[i] && c > 0 ) c--, cout << i << ' ';
    }

    return 0;

}


