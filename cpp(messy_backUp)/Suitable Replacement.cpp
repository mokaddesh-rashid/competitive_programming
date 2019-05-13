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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int v, ar[26], br[26], vr[26];
string str,ssr;

int chk(int x)
{
    int a,b,c=0;

    FOR(i,0,25)
    {
        c+=max(0,(br[i]*x)-ar[i]);
        vr[i]=max(0,(br[i]*x)-ar[i]);

    }
    if(c<=v) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,st,en,mid,a,b,c,x,y,z;

    cin>>str; n=str.size();
    FOR(i,0,n-1)
    {
        if(str[i]=='?') v++;
        else
        {
            x=str[i]-'a';
            ar[x]++;
        }
    }

    cin>>ssr; m=ssr.size();
    FOR(i,0,m-1)
    {
        x=ssr[i]-'a';
        br[x]++;
    }

    c=st=0; en=(n/m)+1;
    while(st<=en)
    {
        mid=(st+en)>>1;
        if(chk(mid)) st=mid+1, c=max(c,mid);
        else en=mid-1;
    }
    a=chk(c);

    FOR(i,0,n-1)
    {
        if(str[i]=='?')
        {
            FOR(i,0,25)
            {
                if(vr[i]>0)
                {
                    char ch='a'+i;
                    cout<<ch;
                    vr[i]--;
                    break;
                }
                if(i==25) cout<<'a';
            }

        }
        else cout<<str[i];
    }
    return 0;
}


