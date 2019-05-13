#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

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
#define LL           long long
#define NL '\n'
#define MAX 1000005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int cnt[1000010], cn[1000010];
char st[1000010];
string str;
int wl[1000010], f[1000010], s[1000010], ar[1000010];
int main()
{
    //inf;
    //outf;
    int tc, ca = 1;
    sf(tc);
    FOR(ca,1,tc)
    {
        mem(cnt,0); mem(cn,0);
        int n, m, i, j, x=0, y,a,b,c=0;
        scanf("%s",st);
        str=st; n=str.size();
        FOR(i,0,n-1)
        {
            if(str[i]=='C') x+=1, wl[i+1]=1;
            else x-=1, wl[i+1]=-1;
            ar[i+1]=x;
            //cout<<x<<' ';
        }
        //cout<<NL;
        x=100000000;
        FOR(i,1,n)
        {
            x=min(x,ar[i]);
            f[i]=x;
        }
        x=100000000;
        REV(i,n,1)
        {
            x=min(x,ar[i]);
            s[i]=x;
        }
        x=0;
        FOR(i,1,n)
        {
            x-=wl[i-1];
            a=s[i]; b=f[i-1];
            if(i==1)
            {
                if(a>=0) cnt[i]=1;;
            }
            else
            {
                //cout<<x<<' '<<ar[n]<<' '<<a<<' '<<b<<NL;
                a+=x; b+=(ar[n]+x);
                if(a>=0&&b>=0) cnt[i]=1;
            }
            //cout<<s[i]<<' '<<f[i-1]<<' '<<a<<' '<<b<<NL;
        }

        ///**88888
        x=j=0;
        REV(i,n-1,0)
        {
            if(str[i]=='C') x+=1, wl[j+1]=1;
            else x-=1, wl[j+1]=-1;
            ar[j+1]=x; j++;
            //cout<<x<<' ';
        }
        //cout<<NL;
        x=100000000;
        FOR(i,1,n)
        {
            x=min(x,ar[i]);
            f[i]=x;
        }
        x=100000000;
        REV(i,n,1)
        {
            x=min(x,ar[i]);
            s[i]=x;
        }
        x=0;
        FOR(i,1,n)
        {
            x-=wl[i-1];
            a=s[i]; b=f[i-1];
            if(i==1)
            {
                if(a>=0) cn[i]=1;
            }
            else
            {
                //cout<<x<<' '<<ar[n]<<' '<<a<<' '<<b<<NL;
                a+=x; b+=(ar[n]+x);
                if(a>=0&&b>=0) cn[i]=1;
            }
            //cout<<s[i]<<' '<<f[i-1]<<' '<<a<<' '<<b<<NL;
        }
        b=n;
        FOR(i,1,n)
        {
            if(i==1)
            {
                a=max(cnt[1],cn[1]);
                if(a==1) c++;
            }
            else
            {
                a=max(cnt[i],cn[b]); b--;
                if(a==1) c++;
            }
        }
        pf( "Case %d: %d\n", ca,c);
    }
    return 0;
}
