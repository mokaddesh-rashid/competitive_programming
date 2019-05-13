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
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

string str[1000], chk;
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc,r;
    cin>>tc;
    FOR(tt,1,tc)
    {
        cin>>r;
        cout<<"Case "<<r<<NL;
        int i,j,k,a,b,c,x,y,z,n,m;
        cin>>n>>m;
        FOR(i,0,n-1)
        {
            cin>>str[i];
        }
        FOR(i,0,m-1)
        {
            a=0;
            cin>>chk;
            FOR(j,0,n-1)
            {
                if(str[j].size()==chk.size())
                {
                    b=0;
                    FOR(k,0,chk.size()-1)
                    {
                       if(chk[k]!=str[j][k]) b++;
                    }
                    if(b==1) a=1;
                }
            }
            if(a==1) cout<<"YES"<<NL;
            else cout<<"NO"<<NL;
        }
    }
    return 0;
}
