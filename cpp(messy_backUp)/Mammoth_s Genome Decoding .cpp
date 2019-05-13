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
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

string str;
int main()
{
    ios::sync_with_stdio(false);
    int i, j, x, y, n, m, a, c, g, t, q, chk = 0;

    cin >> n;
    cin >> str;
    x = a = c = g = t = q = 0;

    FOR(i,0,n-1)
    {
        if(str[i]=='A')a++;
        else if(str[i]=='C')c++;
        else if(str[i]=='G')g++;
        else if(str[i]=='T')t++;
        else q++;
    }

    chk = n/4;
    if( a > chk || c > chk || g > chk || t > chk || n%4 ) x = 1;
    if( x == 1 ) cout << "===";
    else
    {
        FOR(i,0,n-1)
        {
            if(str[i]=='?')
            {
                if( a < chk ) a++, str[i] = 'A';
                else if( c < chk ) c++, str[i] = 'C';
                else if( g < chk ) g++, str[i] = 'G';
                else if( t < chk ) t++, str[i] = 'T';
            }
        }
        cout << str;
    }
    return 0;

}


