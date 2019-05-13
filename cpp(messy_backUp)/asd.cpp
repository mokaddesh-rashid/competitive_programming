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
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef pair<int,int> pii;
typedef long long LL;

const int MAX = 300010;

LL n, ara[MAX], bra[MAX], prin;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int n, m;

    cin >> n >> m;
    FOR(i,0,n-1) cin >> ara[i];
    FOR(i,0,m-1) cin >> bra[i];

    sort(ara, ara + n);
    reverse(ara, ara + n);

    sort(bra, bra + n);
    reverse(bra, bra + n);

    FOR(i,0,m-1)
    {
        if(ara[0] > bra[i])
        {
            cout << -1 << endl;
            return 0;
        }

        prin += max(bra[i], ara[0]);
    }
    FOR(i,1,n-1)
        prin += (LL)ara[i] * m;

    cout << prin << endl;
    return 0;
}
