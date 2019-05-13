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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

struct node
{
    LL v, pa, st, en;
}dfa[1010];

string str[110] , ans;
vector<int> mat[110];
int cnt[1000], in[1000];
int ck;

void dfs( int p )
{
        in[p]--;

        if( in[p] > 0 ) return;
        dfa[p].st = 1;
        char ch = p+'a';
        ans = ans+ch, cnt[p]++;

        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            //cout << p << ' ' << x << ' ' << endl;// << dfa[x].st << ' ' << dfa[x].en << endl;
            if( dfa[x].st == 0 ) dfs(x);
            else if( dfa[x].st == 1 && dfa[x].en == 0 ) ck = 1;
        }
        dfa[p].en = 1;
}




int chk( int s, int t, int p )
{
    int a = 1, b, c, x, y, z, i, j, n, m;

    n = str[s].size();
    m = str[t].size();

    for( i=0; i<m; i++ )
    {
        if( str[s][i] != str[t][i] ) a = 0;
    }

    if( a == 1 && m < n ) ck = 1;

    if( n <= p || m <= p ) return 0;
    //cout << 'h' << endl;
    for( i=0; i<p; i++ )
    {
        if( str[s][i] != str[t][i] ) return 0;
    }

    return 1;

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    ans = "";
    int i, j, x, y, n, m;

    cin >> n;

    for( i=0; i<n; i++ )
        cin >> str[i];

    int a, b, c;

    for( i=0; i<n-1; i++ )
    {
        if( str[i][0] != str[i+1][0] )
        {
            x = str[i][0]-'a';
            y = str[i+1][0]-'a';
            mat[x].push_back( y );
            in[y]++;
        }
    }

    for( i=1; i<=100; i++ )
    {
        for( j=0; j<n-1; j++ )
        {
            a = chk( j, j+1, i );
            if( a == 1 && str[j][i] != str[j+1][i] )
            {
                x = str[j][i]-'a';
                y = str[j+1][i]-'a';
                mat[x].push_back( y );
                in[y]++;
            }
        }
    }

    for( i=0; i<n-1; i++ )
    {
        x = str[i][0]-'a';
        if( ( str[i][0] != str[i+1][0] ) && ( dfa[x].st == 0 ) && in[x] <= 0 ) dfs( x );
    }

    for( i=1; i<=100; i++ )
    {
        for( j=0; j<n-1; j++ )
        {
            a = chk( j, j+1, i );
            x = str[j][i]-'a';
            if( a == 1 && str[j][i] != str[j+1][i] &&  dfa[x].st == 0  && in[x] <= 0 ) dfs( x );
        }
    }



    //cout << ck << endl;

    for( i=0; i<26; i++ )
    {
        if( dfa[i].st == 0 && mat[i].size() > 0 ) ck = 1;
    }

    if( ck == 1 ) cout << "Impossible\n";
    else
    {
        cout << ans;
        for( i=0; i<26; i++ )
        {
            char ch = i+'a';
            if( cnt[i] == 0 ) cout << ch;
        }
    }

    return 0;

}



