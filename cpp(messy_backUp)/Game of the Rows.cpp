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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

class compare
{
public:
    bool operator()(int x,int y)
    {
        int a=x%2, b=y%2;
        if(a>b) return x>y;
        else return x<y;
    }
};
int ar[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,c,a,b=0,d,o=0,k=0, lo=0;

    cin>>n>>m; c=n*2; d=n*1;

    FOR(i,0,m-1)
    {
        cin>>ar[i];
        if(ar[i]%2) lo++, ar[i]--;
    }
    sort(ar,ar+m,compare());
    //FOR(i,0,m-1) cout<<ar[i]<<' ';
    //cout<<NL;

    FOR(i,0,m-1)
    {
        a=ar[i];
        while(a>=4&&d>0)
        {
            d--;
            a-=4;
        }
        while(a>=2&&c>0)
        {
            c--;
            a-=2;
        }
        while(a>0&&d>0)
        {
            if(a>=3) d--;
            else if(a==2) o++,d--;
            else if(a==1) d--, c++;

            a-=4;

        }
        while(a>0&&c>0)
        {
            c--;
            a-=2;

        }
        ///cout<<o<<' '<<c<<' '<<d<<' '<<a<<NL;
        if(a>0) k=1;
    }
    d*=2;
    if(lo>o+c+d) k=1;
    if(k==1) cout<<"NO"<<NL;
    else cout<<"YES"<<NL;
    return 0;
}


