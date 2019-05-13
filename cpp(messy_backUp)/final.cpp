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
#define mod          (LL)100000000007
#define mod2          (LL)100000000000007
#define LL           long long
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


LL bm(LL n, LL p, LL m)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % m;

    LL ret = bm(n, p/2, m);
    ret = (ret * ret) % m;
    if(p % 2) ret = (ret * n) % m;
    return ret%m;
}

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
int hashing( string text, string pattern )
{
    LL i, j, x, y, n, m, k, p_val = 0, a, b, c, chk = 0, cnt = 0;
    n = text.size();
    m = pattern.size();
    x = m-1;

    FOR(i,0,m-1)
    {
       a = bm(26, x, mod);
       b =  pattern[i]-'a';
       c = a*b;
       p_val += c;
       p_val %= mod;
       x--;
    }
    ///cout << p_val << endl;
    j = 0;
    x = m-1;
    FOR(i,0,m-1)
    {
      a = bm(26, x, mod );
      b = text[i]-'a';
      c = a*b;
      chk += c;
      chk %= mod;
      x--;
    }
    ///cout << chk << endl;
    x = m-1;
    if( chk == p_val ) return 1;
    FOR(i,m,n-1)
    {
       a =  bm( 26, x, mod);
       b = text[i-m]-'a';
       c = a*b;
       chk -= c;
       chk %= mod;
       chk *= 26;
       chk += text[i]-'a';
       chk %= mod;
       if( chk == p_val ) return 1;
    }

    return -1;
}

int chk( int x )
{
    string chk;
    int j = t.size()-x-1;
    int a = 0, b, c;

    if( x >= s.size() ) return -1;

    FOR(i,0,x)
    {
        if( f[i] != t[j] ) a = -1;
        chk = chk+str[i];
        j++;
    }

    b = -1;
    b = hashing( s , chk );
    //cout << a << ' ' << b << ' ' << x << endl;
    return min( a, b );
}

int bs( int en )
{
    int st, mid, a = -1, x;
    st = 0;

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
    FOR(i,0,n-1)
    {
       a = bm( 26, i, mod );
       b = str[i];
       c = a*b;
       p_val += c;
       p_val %= mod;

       d = d*26;
       d += str[j]-'a';
       d %= mod;
       j--;
       //cout << p_val << ' ' << d << ' ' << chk << endl;
       if( p_val == d ) ar[p] = i, p++;
       //cout << ck << endl << endl << endl;

    }

    x = bs( p );

    if( x == -1 ) cout << "Just a legend\n";
    else
    {
        FOR(i,0,x) cout << str[i];
    }
    return 0;

}
