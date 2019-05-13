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

LL n;
struct node
{
    LL mat[111][111];
};

node mat_mul(node a, node b, int modd)
{
    node c;
    FOR(i,1,n)
    FOR(j,1,n)
    {
        LL x=0, y, z;
        FOR(k,1,n)
        {
            x += (a.mat[i][k]*b.mat[k][j]);
            x %= modd;
        }
        c.mat[i][j]=x;
    }
    return c;
}

node bm(node ba,LL p,LL modd)
{
    //cout<<p<<endl;
    if(p<=1) return ba;
    node ret=bm(ba,p/2,modd);
    ret=mat_mul(ret,ret,modd);
    if(p%2) ret=mat_mul(ret,ba,modd);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int ar[1000];
    FOR(i,1,101)
    {
        if(i==1||i==2) ar[i]=1;
        else ar[i]=ar[i-1]+ar[i-2];
        ar[i]%=10007;
    }
    int tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        node ole;
        mem(ole.mat,0);
        LL i, j, x=0, y, m, a;
        cin>>m>>n;
        FOR(i,2,n) ole.mat[1][i]=1;
        FOR(i,2,n) ole.mat[i][i-1]=1;
        ole=bm(ole,m-n,10007);
        j=n;
        FOR(i,1,n)
        {
            a=ole.mat[1][i]*ar[j];
            x+=a;
            x%=10007;
            j--;
        }
        ///cout<<x<<endl;
        if(m<n) cout<<"Case "<<t<<": "<<(ar[m]*2)%10007<<NL;
        else cout<<"Case "<<t<<": "<<max(x*2,(LL)0)%10007<<NL;
    }
    return 0;
}


