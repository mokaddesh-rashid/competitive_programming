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

int ar[200010], ans[200010];
string str;

class Compare
{
public:
    bool operator()(pr x,pr y)
    {
        if(x.F==y.F) return x.S<y.S;
        else return x.F>y.F;
    }
};
set<pr,Compare>ms;
set<pr>::iterator it;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,k,q,a,b,c;
    pr ck;

    cin>>n>>k>>q;
    k=min(n,k);

    FOR(i,0,n-1)
    {
        cin>>ar[i];
        ar[i+n]=ar[i];
    }
    m=2*n; x=a=b=0;
    REV(i,m-1,0)
    {
        if(ar[i]==1) x++;
        else x=0;
        ms.insert(MK(x,i));

        while(true)
        {
            it=ms.begin(); ck=*it;
            //cout<<i<<' '<<ck.S<<' '<<ck.F<<NL;
            if(ck.S+ck.F-1<=i+n-1) break;

            ms.erase(ms.begin());
            if(ck.S>i+n-1) continue;
            else
            {
                ck.F=i+n-ck.S;
                //cout<<ck.F<<' ';
                ms.insert(ck);
            }
        }
        ans[i]=ck.F;
        //cout<<i<<' '<<ans[i]<<NL;
       /// cout<<NL; cout<<NL;
    }

    a=n;
    cin>>str;
    FOR(i,0,q-1)
    {
        if(str[i]=='?') cout<<min(k,ans[a])<<NL;
        else
        {
            a--;
            if(a==-1) a=n;
        }
    }
    return 0;
}
