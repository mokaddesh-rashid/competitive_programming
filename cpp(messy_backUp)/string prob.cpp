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

int visa[100], visb[100];
string str, ss;
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(visa,0); mem(visb,0);
        int n,m,x,c=mod,y;
        cin>>n>>m;
        cin>>str>>ss;
        FOR(i,0,n-1)
        {
            x=str[i]-'a';
            visa[x]++;
        }
        FOR(i,0,m-1)
         {
            x=ss[i]-'a';
            visb[x]++;
         }

        FOR(i,0,25)
        {
            if(visb[i]!=0)
            {
                x=visa[i]/visb[i];
                c=min(c,x);
            }
        }
        cout<<c<<NL;
    }
    return 0;
}

