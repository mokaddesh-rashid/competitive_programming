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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<LL>::iterator ii;

LL n, m, t;
string str[20], st[20], sou, des;



LL rec(string s, LL y )
{
    if( s == des )
        {
            t = min( t, y );
            return y;
        }
    if( y > 10 )
        return maxx;
    if( t < y )
        return maxx;
    LL sz = s.size(), b, c, temp = maxx;

    string re;
    for( LL i=0; i<n; i++ )
    {
       int c = 0;
        re = s;
        //cout << re << endl;
       int pos = re.find(str[i]);

       while(pos != string::npos)
         {
           // cout << pos << endl;
            c = 1;
            re.replace(pos,str[i].size(),st[i]);
            pos = re.find(str[i],pos+st[i].size());
         }
       // cout << re << endl;
       if( c == 1 )
        temp = min( temp, rec( re, y+1 ) );
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    while( true )
    {

    LL i, j, x, y, m;

    cin >> n ;

    if( n == 0 )
        break;

    for( i=0; i<n; i++ )
        {
            cin >> str[i] >> st[i];
            //str[i+1] = st[i];
            //st[i+1] = str[i];
        }

    cin >> sou;
    cin >> des;
    t = maxx;
    x = rec( sou, 0 );
    if( x == maxx )
        x = -1;
    cout << x << endl;

    }


    return 0;

}


