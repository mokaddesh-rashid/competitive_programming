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
#define MAX 100010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int xo, jo, x, ans[32];

int Xor(int f,int s,int ba)
{
    int a=f,b=1,c=0;
    REV(i,31,0)
    {
       xo=f%ba; f/=ba;
       jo=s%ba; s/=ba;
       a=((xo+jo)%ba)*b;
       b*=ba;
       c+=a;
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;

    sf(tc);//cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,n,m,x=0,a,b,c,k;

        sff(a,b);//cin>>a>>b>>k;
        sf(k);

        while(a%(k*k)!=0&&a<=b)
        {
            x=Xor(a,x,k);
            a++;
        }
        while(a<=b)
        {
            if(b%(k*k)==k*k-1)break;
            x=Xor(b,x,k);
            b--;
        }
        pf("%d\n",x);//cout<<x<<NL;
    }
    return 0;
}


