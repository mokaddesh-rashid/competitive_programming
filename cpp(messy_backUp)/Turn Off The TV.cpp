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
#define MAX 1000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

pr ar[MAX];
int val[MAX],dor[MAX],t,cnt[MAX],sm[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m=0;

    sf(n);
    FOR(i,0,n-1)
    {
        sff(ar[i].F,ar[i].S), val[m]=ar[i].F; val[m+1]=ar[i].S; m+=2;
        val[m]=ar[i].F+1; val[m+1]=ar[i].S+1; m+=2;
    }
    sort(val,val+m);
    FOR(i,0,m-1)
        if(val[i]!=val[i+1]||i==m-1) dor[t]=val[i],t++;

    FOR(i,0,n-1)
    {
        ar[i].F=lower_bound(dor,dor+t,ar[i].F)-dor;
        ar[i].S=lower_bound(dor,dor+t,ar[i].S)-dor;
        cnt[ar[i].F]++; cnt[ar[i].S+1]--;
    }
    int a=0,b,c,d,e=0;
    FOR(i,0,MAX-1)
    {
        a+=cnt[i];
        if(a==1)sm[i]=1;
    }
    a=0;
    FOR(i,0,MAX-1)
    {
        a+=sm[i];
        sm[i]=a;
    }

    FOR(i,0,n-1)
    {
        a=ar[i].F;b=ar[i].S;
        c=sm[b];
        if(a!=0)c-=sm[a-1];

        if(c==0)
        {
            pf("%d\n",i+1);
            e=1;
            break;
        }
    }
    if(e==0)pf("-1\n");

    return 0;
}


