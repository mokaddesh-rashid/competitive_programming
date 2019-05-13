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
typedef pair<int,int> pr;

int ar[12], n;
struct Matrix
{
    LL mat[12][12];
};

Matrix mat_mul(const Matrix &a,const Matrix &b)
{
    Matrix c;
    FOR(i,1,n)
    FOR(j,1,n)
    {
        LL x=0, y, z;
        FOR(k,1,n)
        {
            x += (a.mat[i][k]*b.mat[k][j]);
            if(x>mod) x%=mod;
        }
        c.mat[i][j]=x;
    }
    return c;
}

Matrix bm(Matrix ba,int p)
{
    if(p==1||p==0) return ba;
    Matrix ret=bm(ba, p/2);
    ret=mat_mul(ret,ret);
    if(p%2) ret=mat_mul(ret,ba);
    return ret;
}

int main()
{
    ///ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    sf(tc);///cin>>tc;
    FOR(tt,1,tc)
    {
        mem(ar,0);
        LL i, j, x=1, y, m;
        int p;
        sff(n,p);///cin>>n>>p;
        m=mod;

        Matrix ole;
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                if(i==1&&j==1) ole.mat[i][j]=1;
                else if(i==1&&j==n) ole.mat[i][j]=1;
                else if(j==i-1) ole.mat[i][j]=1;
                else ole.mat[i][j]=0;
            }
        }

        FOR(i,1,n) ar[i]=1;
        ar[1]=2;

        if(p<=n)
        {
            pf("Case %d: %d\n",tt,ar[n-p+1]);
            ///cout<<"Case "<<tt<<": "<<ar[n-p+1]<<NL;
            ///cout<<<<endl;
            continue;
        }
        ole=bm(ole,p-n);
        y=0;
        FOR(i,1,n)
        {
           /// cout<<ar[i]<<' '<<ole.mat[1][i]<<' '<<endl;
            y += (LL)(ar[i]*ole.mat[1][i]);
            y%=m;
        }
        pf("Case %d: %d\n",tt,y);
        ///cout<<"Case "<<tt<<": "<<y<<NL;
        ///cout<<y<<endl;
    }
    return 0;
}
