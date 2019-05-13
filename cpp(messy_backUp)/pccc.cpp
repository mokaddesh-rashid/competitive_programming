#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
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
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<LL,LL> pr;

int nx[100010], n, m;
vector<int> mat[100020];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int i,j,a=0,b,c,x,y,z,p,q;
    cin>>n>>m;
    FOR(i,0,100010) mat[i].PB(0);
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            cin>>a;
            mat[i].PB(a);
        }
    }

    FOR(i,1,m)
    {
        for(j=1; j<=n; j)
        {
            p=j;
            a=mat[j][i];
            while(j<=n&&a<=mat[j][i])
            {
                a=max(a,mat[j][i]);
                j++;
            }
            FOR(k,p,j-1)
            {
               nx[k]=max(nx[k],j-1);
            }

        }
    }
    cin>>q;
    FOR(i,1,q)
    {
        cin>>a>>b;
        if(nx[a]>=b) cout<<"Yes"<<NL;
        else cout<<"No"<<NL;
    }

    return 0;
}
