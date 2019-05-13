//#include <bits/stdc++.h>
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
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int ar[400010], n, m, k, cp[400010];
LL dp[400010];

LL rec(int x)
{
    LL temp=minn,a,b,c,y,z;

    if(x==n) return 0;
    if(x>n) return minn;
    if(cp[x]!=-1) return dp[x];
    FOR(i,0,m)
    {
       a=ar[x]*(i+k);
       b=rec(x+i+k);
       temp=max(temp,a+b);
    }
    cp[x]=0;
    return dp[x]=temp;
}
int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(cp,-1);
    LL i, j, x, y=0;
    sff(n,k);///cin>>n>>k;
    m=n%k;
    FOR(i,0,n-1) sf(ar[i]), y+=ar[i];///cin>>ar[i];
    sort(ar,ar+n);
    x=rec(0);
    pf("%lld\n",y-x);///cout<<x<<NL;
    return 0;
}
