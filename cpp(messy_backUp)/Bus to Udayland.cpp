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

string str[10010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y, n, m;

    cin >> n ;

    for( i=0; i<n; i++ )
    {
        cin >> str[i];

        if( str[i][0] == 'O' && str[i][1] == 'O' && x == 0 )
        {
            str[i][0] = '+';
            str[i][1] = '+';
            x = 1;
        }
        else if( str[i][3] == 'O' && str[i][4] == 'O' && x == 0 )
        {
            str[i][3] = '+';
            str[i][4] = '+';
            x = 1;
        }

    }

    if( x == 0 )
      cout << "NO";

    else
    {
        cout << "YES" << endl;
    for( i=0; i<n; i++ )
        cout << str[i] << endl;

    }

    return 0;

}


