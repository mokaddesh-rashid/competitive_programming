#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define si(a)    scanf("%d", &a)
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
#define MAX 2000010
#define SZ 2000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL que[MAX],ar[MAX];
int h,r;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,c=0;
    LL a,b;

    si(n);///cin>>n;
    FOR(i,0,n-1)sf(ar[i]);//cin>>ar[i];
    sort(ar,ar+n,greater<LL>());

    i=0;
    while(true)
    {
        while(ar[i]==ar[i+1]&&i<n)
        {
            i++;
        }
        while(ar[i]==que[h])
        {
            i++;
        }

        a=b=0;
        if(i<n)a=ar[i];
        if(h!=r)b=que[h];

        ///cout<<a<<' '<<b<<NL;
        if(max(a,b)<=1)break;

        if(a>b)
        {
            if(a/2>1)
            if(h==r||que[r-1]!=a/2) que[r]=a/2, r++, r%=MAX;
            i++;
            c++;
        }
        else
        {
            if(b/2>1)
            if(h==r||que[r-1]!=b/2) que[r]=b/2, r++, r%=MAX;
            h++; h%=MAX;
            c++;
        }
    }

    cout<<c<<NL;
    return 0;
}


