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
#define M1          1000000007
#define Mo          1000000000
#define M2          100000007
#define B1          29
#define B2          31
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

pr ar[MAX], inv[MAX], po[MAX], br[MAX];
char str[MAX];

LL bm(LL n, LL p, int m)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % m;

    LL ret = bm(n, p/2, m);
    ret = (ret * ret) % m;
    if(p % 2) ret = (ret * n) % m;
    return ret%m;
}

LL modinv( LL n, LL p )
{
    return bm( n, p-2, p );
}

void info()
{
    LL x=1,y=1;

    FOR(i,0,MAX-1)
    {
        po[i].F=x; x*=B1; x%=M1;
        po[i].S=y; y*=B2; y%=M2;
    }
    FOR(i,0,MAX-1)
    {
        inv[i].F=modinv(po[i].F,M1);
        inv[i].S=modinv(po[i].S,M2);
    }
}

void hasho(int n)
{
    LL m,i,j,a,b,c,x=0,y=0,z;

    FOR(i,0,n-1)
    {
       a=str[i]-'a';a+=2;
       x+=(po[i].F*a); y+=(po[i].S*a);
       x%=M1; y%=M2;
       ar[i].F=x;  ar[i].S=y;
    }
}

LL sub_hasho(pr ar[],int l,int r)
{
    LL a,b,c,x,y,z;

    x=ar[r].F; x+=M1;
    if(l!=0) x-=ar[l-1].F;
    x*=inv[l].F;
    x%=M1;

    y=ar[r].S; y+=M2;
    if(l!=0) y-=ar[l-1].S;
    y*=inv[l].S;
    y%=M2;

    return x*Mo+y;
}
///always check kokhono neg keso hoitese naki
int cnt[MAX],on[MAX];
char so[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    info();

    string po;
    int i,j,n,m,p;
    LL a,b,c=0,x,y,z,co=0;
    pr d,e;

    cin>>n>>m;
    cin>>po; z=po.size();
    FOR(i,0,m-1)
    {
        cin>>a;a--;
        cnt[a]=1; on[i]=a;
    }

    a=-1; p=0;
    FOR(i,0,n-1)
    {
       if(cnt[i]!=0)
       {
           p=max(p,i);
           c=p-i;
           b=i+z;
           while(p<b)
           {
               str[p]=po[c];
               p++;c++;
           }
       }
       else if(p<=i)co++, str[p]=('a'-1);
    }

    hasho(n);

    if(m==0)
    {
        a=bm(26,n,M1);
        a%=M1;
        cout<<a<<NL;
    }
    else
    {
        a=sub_hasho(ar,on[0],on[0]+z-1);

        FOR(i,1,m-1)
        {
            b=sub_hasho(ar,on[i],on[i]+z-1);
            if(a!=b)co=-1;
        }
        if(co==-1)cout<<0<<NL;
        else
        {
            a=bm(26,co,M1);
            cout<<a<<NL;
        }
    }

    return 0;
}
