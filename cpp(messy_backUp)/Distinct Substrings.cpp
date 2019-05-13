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
pair<int,int>ooh[1010];
struct info
{
    int f, s, p;
}ar[1010];
int ls[1010], cnt[1010], n, m, sfx[22][1010], a;///sfx is suffix array
string str;
vector<int> mat[1010], pos[1010], mt[1010], ps[1010];

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
    if( l > 0 && y+l < n && x+l < n )
            return l + lcp( x+l, y+l );

        return l;


}

int chk( int i, int j, int k )///length jodi string pass kore ta handle kori nai
{
    int l = 0, p = -1;

    while( l*2 <= k )
    {
        if( l == 0 )
            l = 1;
        else
            l *= 2;
        p++;
    }

    if( sfx[p][i] < sfx[p][j] )
        return 1;
    if( sfx[p][i] > sfx[p][j] )
        return 2;
    if( l == k )
        return 0;

    return chk( i+l, j+l, k-l );

}

int fin_str( int x, int l, int st, int en )
{
    int mid, ck, p;

    while( st <= en )
    {
        mid = (st+en)/2;
        p = mid;
        mid = ooh[mid].second;
        //cout << p << endl;
        if( mid+l <= n )
        {
            ck = chk( x, mid, l );
            //cout << x << ' ' << mid << ' ' << l << ' ' << ck << 'k' << endl;
            if( ck == 0 )
                return 0;
            else if( ck == 1 )
                en = p-1;
            else
                st = p+1;
        }
        else
        {
            ck = chk( x, mid, n-mid );
            //cout << x << ' ' << mid << ' ' << n-mid << ' ' << ck << 'l' << endl;
            if( ck == 0 || ck == 1 )
                en = p-1;
            else
                st = p+1;
        }
    }

    return 1;
}

int main()
{
    ios::sync_with_stdio(false);

   // inf;
   // outf;
    int ca;

    cin >> ca;

    while( ca-- )
    {
        memset( ls, 0, sizeof(ls) );
        memset( sfx, 0, sizeof(sfx) );
        memset( cnt, 0, sizeof(cnt) );
        int i, j, x, y, z , mx = 0, p, t = 0, l, st, en, mid;
        a = 0; /// global && it is used to remeber the row i will fill of saffix array
        cin >> str;
        n = str.size();
        for( i=0; i<n; i++ )
        {
            x = str[i];
            x = str[i]-65;
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
            x = str[i]-65;
            ls[i] = cnt[x];
            sfx[a][i] = ls[i];

        }
        a++;
        m = log(n)/log(2);
        m++;

        x = 1;
        while( x <= n )
        {
            for( i=0; i<n; i++ )
            {
                ar[i].p = i;
                ar[i].f = ls[i];
                ar[i].s = -1;
                if( i+x < n )
                    ar[i].s = ls[i+x];

            }

            call_sort();
            x *= 2;
        }

        for( i=0; i<n; i++ )
            ooh[i].first = sfx[a-1][i], ooh[i].second = i;

        sort( ooh, ooh+n );
        cout << endl;
        for( i=0; i<n; i++ )
        {
                x = ooh[i].second;
                while( x < n )
                {
                    cout << str[x] ;
                    x++;
                }
                cout << endl;
        }
        int cn = 0;
        for( i=0; i<n-1; i ++ )
        {
                //cout << endl;
                cn += (n-ooh[i].second);
                x = lcp( ooh[i].second, ooh[i+1].second );
                cn -= x;

        }
        cn += (n-ooh[i].second);

        cout << cn << endl;

    }


    return 0;

}


