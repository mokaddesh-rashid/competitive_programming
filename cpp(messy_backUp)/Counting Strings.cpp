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
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

string str;

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, a = 1, b = 1;

    cin >> str;
    n = str.size();
    for( i=1; i<n-1; i++ )
    {
        x = 26;
        a = a*x;
        a = a%mod;
    }

    for( i=0; i<n; i++ )
    {
        if( i == 0 || i == n-1 ) x = str[i]-'A'+1;
        else x = 26;
        b = b*x;
        b = b%mod;
    }

    a = (a-b)%mod;

    for( i=0; i<n; i++ )
    {
        x = 'Z'-str[i]+1;
        a = a*x;
        a = a%mod;
    }
    a--;

    cout << a << endl;

    return 0;

}


