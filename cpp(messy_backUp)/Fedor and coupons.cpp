#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 600005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<LL,LL> pr;


struct node
{
    LL f, s, p;
}ooh[600020];
int cnt[1000010], st[1000100], en[1000100], con[1000100];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i, j, a, b, c, d, x, y, z, n, k, ans = minn, s, e, p = 0;
    cin>>n>>k;
    FOR(i,1,n) {
        cin >> ooh[i].f >> ooh[i].s; ooh[i].p = i;
        con[p] = ooh[i].f; p++;
        con[p] = ooh[i].s; p++;
    }
    sort(con,con+p);
    FOR(i,1,n)
    {
        x = ooh[i].f; x = lower_bound(con,con+p,x)-con; x++;
        y = ooh[i].s; y = lower_bound(con,con+p,y)-con; y++;
        cnt[x]++; cnt[y+1]--;
        ooh[i].f = x; ooh[i].s = y;
        st[x]++; en[y]++;
    }
    FOR(i,1,n)
    {
       cout << ooh[i].f << ' ' << ooh[i].s << endl;
    }
    return 0;
}
