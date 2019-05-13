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

int x, y, xx, yy, xxx, yyy, xxxx, yyyy;
vector<pr> ans;

void chk()
{
    int a = 0;
    if( (xx−x) == (xxx−xxxx) && (yy−y) == (yyy−yyyy) ) a = 1;
    if( xxx−x==xx−xxxx && yyy−y==yy−yyyy ) a = 1;
    if( xxx−x==xxxx−xx && yyy−y==yyyy−yy ) a = 1;
    ans.PB(MK(xxxx,yyyy));
}
int main()
{
    ios::sync_with_stdio(false);
    int i, j, n, m;

    cin >> x >> y;
    cin >> xx >> yy;
    cin >> xxx >> yyy;

    FOR(i,-1000,1000)
     FOR(j,-1000,1000)
     {
        xxxx = i; yyyy = j;
        chk();
     }
    cout << ans.size();
    return 0;

}

