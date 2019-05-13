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

int ar[MAX],n;

int rec(int p,int f,int s)
{
    if(p==n)return 1;

    if(ar[p]==1)
    {
        if(f==1&&s==2)return  rec(p+1,f,3);
        if(f==1&&s==3)return  rec(p+1,f,2);
        if(f==2&&s==1)return  rec(p+1,3,s);
        if(f==3&&s==1)return  rec(p+1,2,s);
        else return 0;
    }
    if(ar[p]==2)
    {
        if(f==2&&s==1)return  rec(p+1,f,3);
        if(f==2&&s==3)return  rec(p+1,f,1);
        if(f==1&&s==2)return  rec(p+1,3,s);
        if(f==3&&s==2)return  rec(p+1,1,s);
        else return 0;
    }
    if(ar[p]==3)
    {
        if(f==3&&s==1)return  rec(p+1,f,2);
        if(f==3&&s==2)return  rec(p+1,f,1);
        if(f==1&&s==3)return  rec(p+1,2,s);
        if(f==2&&s==3)return  rec(p+1,1,s);
        else return 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j;

    cin>>n;
    FOR(i,0,n-1)cin>>ar[i];
    if(rec(0,1,2))cout<<"YES";
    else cout<<"NO";
    return 0;
}


