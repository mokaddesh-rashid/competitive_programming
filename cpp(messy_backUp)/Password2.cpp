#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           unsigned long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
typedef pair<int,int> pr;

string str, f, s, t;
int n, m, ar[1000010];
LL p_val;


void make()
{
    FOR(i,0,n-1)
    {
       if( i != n-1 ) f = f+str[i];
       if( !( i == 0 || i == n-1 ) )s = s+str[i];
       if( i != 0 ) t = t+str[i];
    }
    //cout << f << endl << s << endl << t << endl;
}

int chk( int x )
{
    string chk;
    int j = t.size()-x-1;
    int a = 0, b, c;
    if( x >= s.size() ) return -1;
    FOR(i,0,x)
        chk = chk+str[i];
    b = -1;
    b = s.find( chk );
    //cout << a << ' ' << b << ' ' << x << endl;
    return min( a, b );
}

int bs( int en )
{
    int st, mid, a = -1, x;
    st = max( 0, en-2);
    while( st <= en )
    {
        mid = (st+en)/2;
        x = chk(ar[mid]);
        if( x == -1 ) en = mid-1;
        else st = mid+1, a = max( a, ar[mid] );
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    string chk="";
    int i, j, st, mid, en, x = -1, ck = -1, p = 0;
    LL a, b, c, d = 0, lame = 0, us = 0;
    LL y, z;
    p_val = 0;

    cin >> str;
    n = str.size();
    make();

    j = n-1;
    n = s.size();
    a = 1;
    FOR(i,0,n-1)
    {
       b = str[i]-'a';
       c = a*b;
       p_val += c;

       d = d*26;
       d += str[j]-'a';

       j--;
       a *= 26;
       //cout << p_val << ' ' << d << ' ' << chk << endl;
       if( p_val == d && lame == us ) ar[p] = i, p++;
       //cout << ck << endl << endl << endl;

    }

    if( p != 0 ) x = bs( p );
    string ans = "";
    if( x == -1 ) cout << "Just a legend\n";
    else
    {
        FOR(i,0,x) ans += str[i];
        cout << ans << endl;
    }
    return 0;

}
