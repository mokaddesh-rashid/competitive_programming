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
#define maxx          (long long) 1000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL chkk( LL x )
{
    LL st, en, mid, a = 0, b, c;
    st = 0;
    en = x;

    while( st <= en )
    {
        mid = (st+en)/2;
        if( mid*3 <= x )
            st = mid+1, a = max( a, mid );
        else
            en = mid-1;
    }
    return a;
}

int chk( LL x )
{
    LL re = x, a, b, c;
    a = x;
    a--;
    a = chkk(a);
    re += a;
    return re;

}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t;

    cin >> t;

    while(t--)
    {

    LL i, j, x = maxx, y, n, m, st, en, mid , z;

    cin >> n ;

    y = n-1;
    x =  chkk(y);
    z = n/2;
    if( n%2 )
        z++;
    z -= (x/2);
    if( x%2 )
        z--;
    //cout << z << endl;
    cout << n/2+z << endl;

    }

    return 0;

}


