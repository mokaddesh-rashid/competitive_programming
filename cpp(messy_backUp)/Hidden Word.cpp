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

struct node
{
    LL v, pa, l;
}dfa[100010];

vector<int> mat[100010], st;
string ans, ans, ck;

void dfs( int p )
{
        dfa[p].v = 1;
        char ch = p+'a';

        if( ck == 0 ) ans = ans+ch;
        else ans2 = ans2+ch;

        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                dfa[x].l = dfa[p].l+1;
                dfa[x].pa = p;
                dfs(x);
                if( p == st ) ck = 1;
            }
        }
}


string str;
int cnt[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c, d;

    cin >> str;
    n = 27;
    a = 0;

    for( i=1; i<n; i++ )
    {
        x = str[i]-'a', y = str[i-1]-'a';
        if( x == y ) a = 1;
        mat[x].push_back( y );
        mat[y].push_back( x );

    }

    for( i=0; i<27; i++ )
        for( j=0; j<27; j++ )
    {
        if( str[i] == str[j] && i != j ) x = str[i]-'a';
    }

    st = x;
    ans = ans1 = "";

    if( a == 0 ) dfs(x);

    b = ans.size();
    c = ans1.size();


    if( a == 1 ) cout << "Impossible";
    else if( b == c )
    {
        cout << ans << endl << ans1 << endl;
    }
    else if( b > c )
    {
        string lol = "";
        for( i=0; i<b; i++ )
        {
            if( i < 13 ) cout << ans[i];
            else lol = ans[i]+lol;
        }
        cout << endl;
        cout << ans1 << lol ;
    }
    else if( b > c )
    {
        string lol = "";
        for( i=0; i<b; i++ )
        {
            if( i < 13 ) cout << ans[i];
            else lol = ans[i]+lol;
        }
        cout << endl;
        cout << ans1 << lol ;
    }


    return 0;

}



