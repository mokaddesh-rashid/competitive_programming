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
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL ar[100010], sm[100010],mx[100010], mn[100010];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i,j,x,y,n,m,a=0,b,c=0,z=0;
        cin>>n>>m;
        FOR(i,0,n-1)
        {
            cin>>ar[i];
        }
        i=j=a=b=0;
        while(i<n||j<n)
        {
            if(j==n) c=1;
            else if(i==j) c=2;
            else if(a+ar[j]>=m) c=1;
            else c=2;
            if(c==1)
            {
                a+=m; a-=ar[i]; a%=m; i++;
            }
            else
            {
                a+=ar[j]; a%=m; j++;
            }
            z=max(a,z);
        }
        cout<<z<<NL;
    }
    return 0;
}
/*
1
6 1943
827 436 391 604 902 153
*/
