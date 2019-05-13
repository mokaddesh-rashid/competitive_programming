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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

struct info
{
    int f, s, p;
}ar[100010];
int ls[100010], cnt[100010], n, m, sfx[22][100010], a;///sfx is suffix array
string str;
vector<int> mat[100010], pos[100010], mt[100010], ps[100010];

void call_sort()
{
    for(int i=0; i<n; i++)
    {
        mat[i].clear();
        mt[i].clear();
        pos[i].clear();
        ps[i].clear();
    }
    int x, y, z, p = 0;

    for(int i=0; i<n; i++)
    {
        p = ar[i].p;
        x = ar[i].f;
        y = ar[i].s;

        if( y >= 0 )
            {
                mat[y].push_back(x);
                pos[y].push_back(p);
            }
        else
        {
            mt[x].push_back(y);
            ps[x].push_back(p);
        }
    }

    for(int i=0; i<n; i++ )
    {
            for( int j=0; j<mat[i].size(); j++ )
            {
              x = mat[i][j];
              p = pos[i][j];
              mt[x].push_back(i);
              ps[x].push_back(p);

            }
    }

    p = 0;
    for(int i=0; i<n; i++ )
    {
        //cout << i << " = ";
            for( int j=0; j<mt[i].size(); j++ )
            {
                //cout << mt[i][j] << ' ';
              if( j>0 && mt[i][j] == mt[i][j-1] )
                p--;
              //cout << i << ' ' << mt[i][j] << ' ' << ps[i][j] << ' ' << p << endl;
              x = ps[i][j];
              sfx[a][x] = p;
              ls[x] = p;
              p++;
            }
       // cout << endl;
    }
    a++;


}

int lcp( int x , int y )
{
    int l = 0, p = 0;

    while( sfx[p][x] == sfx[p][y] )
    {
        if( l == 0 )
            l = 1;
        else
            l *= 2;
        p++;
    }
    //cout << x << ' ' << y << ' ' << y+l << ' ' << n << endl;
    if( l > 0 && y+l < n )
        {

            return l + lcp( x+l, y+l );
        }
        return l;


}

int chk( int i, int j, int k )
{
    while( k-- )
    {
        if( str[i] < str[j] )
            return 1;
        if( str[i] > str[j] )
            return 2;
        i++;
        j++;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int ca;
    cin >> ca;

    while( ca-- )
    {
        memset( ls, 0, sizeof(ls) );
        memset( sfx, 0, sizeof(sfx) );
        memset( cnt, 0, sizeof(cnt) );
        int i, j, x, y , mx = 0, p, t = 0;
        a = 0; /// global && it is used to remeber the row i will fill of saffix array
        cin >> n;
        cin >> str;

        for( i=0; i<n; i++ )
        {
            x = str[i];
            x = str[i]-97;
            cnt[x] = 1;
        }

        x = -1;
        for( i=0; i<26; i++ )
        {
            x += cnt[i];
            cnt[i] = x;
        }

        for( i=0; i<n; i++ )
        {
            x = str[i];
            x = str[i]-97;
            ls[i] = cnt[x];
            sfx[a][i] = ls[i];

        }
        a++;
        m = log(n)/log(2);
        m++;

        x = 1;
        while( x <= n )
        {
           // cout << endl;
            for( i=0; i<n; i++ )
            {
                //cout << ls[i] << ' ';
                ar[i].p = i;
                ar[i].f = ls[i];
                ar[i].s = ls[(i+x)%n];

            }
            //cout << endl;
            call_sort();
            x *= 2;
        }

        for( i=0; i<n; i++ )
        {
                if( sfx[a-1][i] == 0 )
                    {
                        cout << i << endl;
                        break;
                    }
        }
    }
    return 0;

}



