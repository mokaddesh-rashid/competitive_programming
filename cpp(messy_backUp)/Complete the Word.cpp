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
typedef pair<int,int> p_i;


//set<int>::iterator ii;

int vis[1000], pos[1111];
string str, ans;

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = -1, y, n, m, cnt, a, b, c, d;
    cin >> str;
    ans = str;
    n = str.size();
    for( i=0; i<n; i++ )
    {
        if( str[i] > 'Z' )
            str[i] = str[i]-32;
    }
    y = cnt = i = j = 0;

    while( i < n && j < n )
    {

        //cout << str[j] << ' ';
        if( j-i+1 <= 26 )
            {

                if( str[j] == '?' )
                    y++;
                else if( vis[str[j]] == 0 )
                {
                    cnt++;
                }
                if( cnt+y == 26 )
                    x = i;
                vis[str[j]]++;
                //cout << str[j] << ' ' << i << ' ' << j << ' ' << cnt << ' ' << y << endl;
                j++;

            }
        else
        {
            vis[str[i]]--;
            if( str[i] == '?' )
                y--;
            else if( vis[str[i]] == 0 ) cnt--;
            //cout << str[i] << ' ' << i << ' ' << j << ' ' << cnt << ' ' << y << endl;
            i++;
        }


    }

    if( x == -1 )
        cout << x << endl;
    else
    {
        string ss;
        a = x+26;
        d = x;
        while( x < a )
        {
            b = str[x]-'A';
            if( str[x] != '?' )
            pos[b]++;
            x++;
        }

        for( i=0; i<26; i++ )
        {
            if( pos[i] == 0 )
            {
                b = i+'A';
                char ch = b;
               // cout << b << ' ' << ch << endl;
                ss = ss+ch;
            }
        }

        j = 0;
        for( i=d; i<a; i++ )
        {
            if( str[i] == '?' )
                ans[i] = ss[j], j++;
        }
        for( i=0; i<n; i++ )
        {
            if( ans[i] == '?' )
                ans[i] = 'A';
        }
        cout << ans;
    }
    return 0;

}


