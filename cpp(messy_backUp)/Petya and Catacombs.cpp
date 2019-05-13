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
int chk(int v)
{
    set<int>sota;
    FOR(i,0,v-1)sota.insert(i);

    FOR(i,v-1,n-1)
    {
        if(sota.find(ar[i])==sota.end())return 0;
        else sota.erase(sota.find(ar[i])), sota.insert(i+1);
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j,st,en,mid,c;

    cin>>n;c=n;
    FOR(i,0,n-1)cin>>ar[i];

    st=0; en=n;
    while(st<=en)
    {
        mid=(st+en)/2;
        if(chk(mid))c=min(c,mid),en=mid-1;
        else st=mid+1;
        cout<<mid<<' '<<chk(mid)<<NL;
    }
    cout<<c<<NL;

    return 0;
}


