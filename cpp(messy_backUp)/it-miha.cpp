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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,LL> pr;

LL ar[MAX], mob[MAX];

void  mobius(LL n)
{
    FOR(i,2,n)
    {
        if(ar[i]==0)
            FORR(j,i,n,i)
            {
                ar[j]++;
                if(j%(i*i)==0)mob[j]=0;
            }
    }
    FOR(i,2,n)
        if(mob[i]!=0&&ar[i]%2==0)mob[i]=1;
}

LL chk(LL v)
{
    LL c=0,a;
    FOR(i,2,MAX-1)
    {
        a=i;
        if(mob[i]==-1) c+=(v/(LL)(a*a));
        else if(mob[i]==1) c-=(v/(LL)(a*a));
    }

    return (v-c);
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(mob,-1); mob[0]=mob[1]=0;

    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        LL st,en,mid;
        mobius(MAX-1);
        LL i,j,n,m,z;

        cin>>n;

        st=1; z=en=n*100;

        while(st<=en)
        {
            mid=(st+en)/2;
            if(chk(mid)>=n)en=mid-1,z=min(z,mid);
            else st=mid+1;
        }
        cout<<z<<NL;
    }
    return 0;
}


