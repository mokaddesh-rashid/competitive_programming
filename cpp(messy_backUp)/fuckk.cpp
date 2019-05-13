#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int mPr[1000100];

void sieve(int n)
{
    int m=sqrt(n);
    FOR(i,2,m)
    {
        if(mPr[i]==0)
        {
            FORR(j,i,n,i)
            {
                mPr[j]=i;
            }
        }
    }
    FOR(i,1,n)
    {
        if(mPr[i]==0) mPr[i]=i;
    }
}
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
int cnt[1000010];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    sieve(1000000);

    mem(cnt,0);
    int i, j, x, y, n, m;
    LL a=1, b, c=0;
    cin>>n;
    FOR(i,1,n)
    {
        cin>>x;
        if(x>0)
        {
            while(x>1)
            {
                y=mPr[x];
                //cout<<y<<' ';
                b=(cnt[y]+1);
                a/=b;
                cnt[y]++;
                b=(cnt[y]+1);
                if(a==0) a=b;
                else a*=b;
                x/=y;
            }
        }
        else if(x<0)
        {
            x*=-1;
            while(x>1)
            {
                y=mPr[x];
                //cout<<y<<' ';
                b=(cnt[y]+1);
                a/=b;
                cnt[y]--;
                b=(cnt[y]+1);
                cnt[y]=max(0,cnt[y]);
                if(a==0) a=b;
                else a*=b;
                x/=y;
            }
        }
        c+=a;
        //cout<<NL<<a<<NL<<NL;
    }
    cout<<c<<endl;
    return 0;
}


