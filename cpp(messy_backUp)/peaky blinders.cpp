#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define F first
#define S second

typedef pair<int,int> pii;
typedef long long LL;
const int MAX = 3005;

pair<pii,int> ara[MAX];
int n, ito[MAX][MAX], devi[MAX], p, s;
int dp[MAX][MAX];

int rec(int px,int sx)
{
    int x = p + s - px - sx;

    if(min(px, sx) < 0) return -60000006;
    if(px == 0) return ito[x][sx];

    int &temp = dp[px][sx];
    if(temp != -1) return temp;
    return temp = max(rec(px - 1, sx) + ara[x].F.F, rec(px, sx - 1) + ara[x].F.S);
}

vector<int> up, dw;
vector<pii> usue;


void prin(int px,int sx)
{
    int x = p + s - px - sx;

    if(px == 0)
    {
        FOR(i,x,n-1)
            usue.push_back( {ara[i].F.S, ara[i].S} );

        sort(usue.begin(), usue.end());
        reverse(usue.begin(), usue.end());

        for(auto x : usue)
            if(dw.size() < s) dw.push_back( x.S );

        return;
    }

    int &temp = dp[px][sx];

    if(temp == rec(px - 1, sx) + ara[x].F.F)
    {
        up.push_back( ara[x].S );
        prin(px - 1, sx);
    }
    else
    {
        dw.push_back( ara[x].S );
        prin(px, sx - 1);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> n >> p >> s;
    FOR(i,0,n-1) cin >> ara[i].F.F, ara[i].S = i + 1;
    FOR(i,0,n-1) cin >> ara[i].F.S;

    sort(ara, ara + n);
    reverse(ara, ara + n);

    int ti = 0;
    REV(i,n-1,0)
    {
        devi[ti] = ara[i].F.S;

        int t = ti;
        while(t && (devi[t] > devi[t - 1])) { swap(devi[t], devi[t - 1]); t--; }
        ti++;

        int c = 0;
        FOR(j,0,ti-1)
        {
            c += devi[j];
            ito[i][j + 1] = c;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(p, s) << endl;
    prin(p, s);
    for(auto x : up) cout << x << ' ';
    cout << endl;
    for(auto x : dw) cout << x << ' ';
    cout << endl;
    return 0;
}

