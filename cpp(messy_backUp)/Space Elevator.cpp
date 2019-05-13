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

struct info
{
    int h,a,c;
}ar[410];

class Compare
{
public:
    bool operator()(info x,info y)
    {
        return x.a<y.a;
    }
};
int n,dp[410][40010];
int rec(int x,int y)
{
    if(x==n) return y;
    if(dp[x][y]!=-1) return dp[x][y];
    int temp=0,a=0;
    FOR(i,0,ar[x].c)
    {
        if(a+y<=ar[x].a) temp=max(temp,rec(x+1,y+a));
        a+=ar[x].h;
    }
    return dp[x][y]=temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i, j, x, y;
    cin>>n;
    FOR(i,0,n-1) cin>>ar[i].h>>ar[i].a>>ar[i].c;
    sort(ar,ar+n,Compare());
    x=rec(0,0);
    cout<<x<<NL;
    return 0;
}


