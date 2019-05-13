#include <bits/stdc++.h>
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
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define sfff(a,b,c)    scanf("%lld %lld %lld", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

LL ar[500010], cnt[500010], n, k;

LL need(int i)
{
    LL x=0, a, b, c;
    if(i+k-1>=n) return maxx;
    FOR(j,i,i+k-1)
    {
        a=ar[j]-ar[i]; x+=a;
    }
    return x;
}
int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL tc;
    sf(tc);///cin>>tc;
    FOR(tt,1,tc)
    {
        mem(cnt,0);
        LL i, j, x=0, y, m, a, b, c, d;
        sff(n,k);//cin>>n>>k;
        FOR(i,0,n-1)
        {
            sf(ar[i]);//cin>>ar[i];
            cnt[ar[i]]++;
        }
        FOR(i,0,n-1)
        {
            if(cnt[ar[i]]>=k) continue;
            else if(i==0)
            {
                FOR(j,i,k-1)
                {
                    a=ar[j]-ar[i]; x+=a;
                    cnt[ar[j]]--; cnt[ar[i]]++;
                    ar[j]=ar[i];
                    //cout<<ar[i]<<' '<<cnt[ar[i]]<<NL;
                }
            }
            else
            {
                a=need(i); b=(ar[i]-ar[i-1])*cnt[ar[i]];
                //cout<<i<<' '<<ar[i]<<' '<<cnt[ar[i]]<<' '<<a<<' '<<b<<NL;
                if(a<b)
                {
                    x+=a;
                    FOR(j,i,i+k-1)
                    {
                        a=ar[j]-ar[i];
                        cnt[ar[j]]--; cnt[ar[i]]++;
                        ar[j]=ar[i];
                    }
                }
                else
                {
                    x+=b; c=ar[i-1], d=ar[i];
                    j=i;
                    while(d==ar[j])
                    {
                        ar[j]=c;cnt[d]--;cnt[c]++;
                        j++;
                    }
                }
            }
        }
        pf("%lld\n",x);//cout<<x<<NL;
    }
    return 0;
}
