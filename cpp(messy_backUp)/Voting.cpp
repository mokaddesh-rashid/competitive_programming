#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
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
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int cnt[200010];
string str;
int main()
{
    ios::sync_with_stdio(false);
    int i, j, x = 0, y = 0, n, m, a, b, c;
    cin >> n;
    cin >> str;
    a = b = 1;
    while( a == 1 && b == 1 )
    {
        a = b = 0;
        FOR(i,0,n-1)
        {
           if( cnt[i] == 0 && str[i] == 'D' ) a = 1;
           if( cnt[i] == 0 && str[i] == 'R' ) b = 1;
           //cout << x << ' ' << y << endl;
           if( cnt[i] == 0 && str[i] == 'D' && y == 0 ) x++;
           else if( cnt[i] == 0 && str[i] == 'D' && y > 0 ) cnt[i]++, y--;
           if( cnt[i] == 0 && str[i] == 'R' && x == 0 ) y++;
           else if( cnt[i] == 0 && str[i] == 'R' && x > 0 ) cnt[i]++, x--;

        }
    }
    if( a == 1 ) cout << 'D';
    else cout << 'R';
    return 0;

}


