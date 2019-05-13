#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

string str, ss, ans;
int n;
int m_t[1001][1001], s_t[1001][1001];

void it_rec()
{
    memset( m_t, 0,sizeof(m_t) );

    for(int i=1; i<=n; i++ )
        for(int j=1; j<=n; j++ )
    {
        if( str[i-1] == ss[j-1] )
        {
            m_t[i][j] = m_t[i-1][j-1] + 1;
            s_t[i][j] = 3;
        }
        else if( m_t[i-1][j] >= m_t[i][j-1] )
        {
            m_t[i][j] = m_t[i-1][j];
            s_t[i][j] = 2;
        }
        else
        {
            m_t[i][j] = m_t[i][j-1];
            s_t[i][j] = 1;
        }
    }

}

void prn( int i, int j )
{
    if( s_t[i][j] == 3 )
    {
        ans =  str[i-1] + ans;// << ss[j] << endl;
        prn( i-1, j-1 );
    }
    else if( s_t[i][j] == 2 )
    {
        prn( i-1, j );
    }
    else if( s_t[i][j] == 1 )
        prn( i, j-1 );
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, m;

    cin >> str >> ss ;

    n = str.size();
    m = ss.size();
    it_rec( );

    cout << m_t[n][m];
    cout << endl;
    prn( n, n );
    cout << ans;



    return 0;

}


