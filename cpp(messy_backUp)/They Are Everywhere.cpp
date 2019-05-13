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

int cnt[1000001], took[100001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m, a, b, c, minn;

    cin >> n ;

    string str;

    cin >> str;

    for( i=0; i<n; i++)
    {
        a = str[i];
        if( cnt[a] == 0 )
        {
            x++;
            cnt[a]++;
        }
    }

    i = 0;
    j = 0;
    a = 0;
    minn = mx;
    while( j < n || i < n )
    {
        if( a < x && j < n )
        {
            b =str[j];
            if( took[b] == 0 )
                a++;
            took[b]++;
            j++;
        }
        if( a == x )
        {
            //cout << i << ' ' << j << endl;
            minn = min( minn, j-i);
            b = str[i];
            if( took[b] == 1 )
                a--;
            took[b]--;
            i++;
        }
        if( j == n && a < x )
            break;
    }

    cout << minn;

    return 0;

}


