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

node mat_mul(node a, node b)
{
    node c;
    FOR(i,1,n)
    FOR(j,1,n)
    {
        LL x=0, y, z;
        FOR(k,1,n)
        {
            x += (a.mat[i][k]*b.mat[k][j]);
        }
        c.mat[i][j]=x;
    }
    return c;
}

node bm(node ba,LL p)
{
    if(p==1||p==0) return ba;
    node ret=bm(ba, p/2);
    ret=mat_mul(ret,ret);
    if(p%2) ret=mat_mul(ret,ba);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i, j, x, y, m;
    //cin>>n>>m;
    n=2;
    node ole;
    ole.mat[1][1]=1; ole.mat[1][2]=1; ole.mat[2][1]=1; ole.mat[2][2]=0;

    ole=bm(ole,11);
    FOR(i,1,n)
    {
        FOR(j,1,n)cout<<ole.mat[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}

