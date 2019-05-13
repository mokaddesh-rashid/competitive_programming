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
#define LL           unsigned int
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
typedef pair<int,int> pr;

string str, f, s, t, text, pattern;
int n, m, ar[1000010];
LL p_val;

LL bm(LL n, LL p)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n;

    LL ret = bm(n, p/2);
    ret = (ret * ret);
    if(p % 2) ret = (ret * n);
    return ret;
}
int hashing( int m )
{
    m++;
    LL i, j, x, y, n, k, p_val = 0, a, b, c, chk = 0, cnt = 0;
    n = str.size();
    n -= 2;
    a = 1;
    REV(i,m-1,0)
    {
       b = str[i]-'a';///b =  pattern[i]-'a';
       c = a*b;
       p_val += c;
       a *= 1007;
    }
    //cout << p_val << 'k' << endl;
    j = 0;
    a = 1;
    REV(i,m-1,0)
    {
      //cout << str[i+1];
      b = str[i+1]-'a';
      c = a*b;
      chk += c;
      a *= 1007;
    }
    //cout << chk << endl;
    x = m-1;
    if( chk == p_val ) return 1;
    a =  bm( 1007, x );
    FOR(i,m,n-1)
    {
       //cout << str[i+1];
       b = str[i-m+1]-'a';
       c = a*b;
       chk -= c;
       chk *= 1007;
       chk += str[i+1]-'a';
       //cout << chk << endl;
       if( chk == p_val ) return 1;
    }
    ///cout << endl;
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, st, mid, en, x = -1, ck = -1, p = 0, f = -1, s = -1;
    LL a, b, c, d = 0, lame = 0, us = 0;
    LL y, z;
    p_val = 0;

    cin >> str;
    n = str.size();
    j = n-1;
    n -= 2;
    a = 1;
    FOR(i,0,n-1)
    {
       b = str[i]-'a';
       c = a*b;
       p_val += c;

       d = d*1007;
       d += str[j]-'a';

       j--;
       a *= 1007;

       if( p_val == d )
       {
          p = f;
          f = i;
          s = p;
       }
    }
    //cout << text << endl;
    //cout << f << ' ' << s << endl;
    string ans = "";
    if( s != -1 )
    {
        a = hashing(s);
        if( a != -1 ) x = s;
    }
    //cout << endl;
    if( f != -1 )
    {
        a = hashing(f);
        if( a != -1 ) x = f;
    }
    //cout << pattern << endl;
    if( x == -1 ) cout << "Just a legend\n";
    else
    {
      FOR(i,0,x) cout << str[i];
    }
    return 0;

}
