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
    LL mat[10][10];
};

node mat_mul(node a, node b, LL mo)
{
    node c;
    FOR(i,1,2)
    FOR(j,1,2)
    {
        LL x=0, y, z;
        FOR(k,1,2)
        {
            x += (a.mat[i][k]*b.mat[k][j]);
            x %= mo;
        }
        c.mat[i][j]=x;
    }
    return c;
}

node bm(node ba,LL p,LL m)
{
    if(p==1||p==0) return ba;
    node ret=bm(ba, p/2, m);
    ret=mat_mul(ret,ret,m);
    if(p%2) ret=mat_mul(ret,ba,m);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    while(cin>>n)
    {
        LL i, j, x=1, y=0, m;
        cin>>m;
        if(n==2)n--;
        if(n==0||n==1) cout<<n;
        else
        {
            FOR(i,1,m) x*=2;
            node ole;
            ole.mat[1][1]=1; ole.mat[1][2]=1; ole.mat[2][1]=1; ole.mat[2][2]=0;
            ole=bm(ole,n-1,x);
            cout<<ole.mat[1][1]<<endl;

        }
    }
    return 0;
}


