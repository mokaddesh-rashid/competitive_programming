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

string str;
int pek[MAX], eat[MAX], np, ea, ar[MAX], br[MAX], tim[MAX];

void up()
{
    int n=(int)str.size();
    np=ea=0;
    FOR(i,0,n-1)
    {
        if(str[i]=='P')pek[np++]=i;
        if(str[i]=='*')eat[ea++]=i;
    }
}

int chk(int v)
{
    int n=np, p=0,a,b,c;
    FOR(i,0,np-1)ar[i]=pek[i], tim[i]=v;

    FOR(i,0,n-1)
    {
        if(p<ea&&abs(ar[i]-eat[p])<=tim[i])
        {
            if(ar[i]>eat[p])
            {
               a=eat[p];
               b=tim[i]-abs(ar[i]-eat[p]);
               b/=2;
               b=ar[i]+b;

               c=tim[i]-(abs(ar[i]-eat[p])*2);
               b=max(b,ar[i]+c);
            }
            else a=ar[i],b=ar[i]+tim[i];

            while(p<ea&&a<=eat[p]&&eat[p]<=b)
            {
                p++;
            }
        }
    }

    if(p==ea)return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    //while(true)
    {
        int i,j,n,m,st,en,mid,c;

        cin>>n;
        cin>>str;
        up();

        en=c=2*MAX;
        st=0;
        while(st<=en)
        {
            mid=(st+en)>>1;

            if(chk(mid))en=mid-1,c=min(c,mid);
            else st=mid+1;
        }
        cout<<c<<NL;
    }

    return 0;
}


