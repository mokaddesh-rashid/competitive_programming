#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 200005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> p_i;


//set<LL>::iterator ii;
pair<LL,LL>ooh[MAX];
struct info
{
    LL f, s, p;
}ar[MAX];
LL ls[MAX], cnt[MAX], n, m, sfx[30][MAX], a;///sfx is suffix array
string str;
vector<LL> mat[MAX], pos[MAX], mt[MAX], ps[MAX];

void call_sort()
{
    for(LL i=0; i<n; i++)
    {
        mat[i].clear();
        mt[i].clear();
        pos[i].clear();
        ps[i].clear();
    }
    LL x, y, z, p = 0;

    for(LL i=0; i<n; i++)
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

    for(LL i=0; i<n; i++ )
    {
            for( LL j=0; j<mat[i].size(); j++ )
            {
              x = mat[i][j];
              p = pos[i][j];
              mt[x].push_back(i);
              ps[x].push_back(p);

            }
    }

    p = 0;
    for(LL i=0; i<n; i++ )
    {
        //cout << i << " = ";
            for( LL j=0; j<mt[i].size(); j++ )
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

LL lcp( LL x , LL y )
{
    LL l = 0, p = 0;

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
            return l + lcp( x+l, y+l );

        return l;


}

LL chk( LL i, LL j, LL k )///length jodi string pass kore ta handle kori nai
{
    LL l = 0, p = -1;

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

LL fin_str( LL x, LL l, LL st, LL en )
{
    LL mid, ck, p;

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

    inf;
   // outf;
    LL ca;

    cin >> ca;

    while( ca-- )
    {
        memset( ls, 0, sizeof(ls) );
        memset( sfx, 0, sizeof(sfx) );
        memset( cnt, 0, sizeof(cnt) );
        LL i, j, x, y, z , mx = 0, p, t = 0, l, st, en, mid;
        a = 0; /// global && it is used to remeber the row i will fill of saffix array
        cin >> str;
        n = str.size();
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
//        cout << endl;
//        for( i=0; i<n; i++ )
//        {
//                x = ooh[i].second;
//                while( x < n )
//                {
//                    cout << str[x] ;
//                    x++;
//                }
//                cout << endl;
//        }
        LL cn = 0;
        for( i=0; i<n; i ++ )
        {
                //cout << endl;
                cn += (n-ooh[i].second);
                l = 1;
                while( ooh[i].second+l <= n )
                {
                    //cout << ooh[i].second << ' ' << l << endl ;
                    LL ck = fin_str( ooh[i].second, l, i+1, n-1 );
                    //cout << ck << endl << endl;
                    if( ck != 0 )
                        break;
                    cn--;
                    l++;

                }


        }

        cout << cn << endl;

    }


    return 0;

}


