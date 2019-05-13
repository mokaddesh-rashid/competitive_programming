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
#define NL "\n"
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int ar[1000100], mn[1000010], que[1000010];
int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, hd=0, tl=0, k;
    sff(n,k);//cin>>n>>k;
    FOR(i,0,n-1) sf(ar[i]);//cin>>ar[i];

    i=j=0;
    while(j<n)
    {
        if(j-i==k)
        {
            if(que[hd]==ar[i]) hd++;
            i++;
        }
        while(tl>hd&&ar[j]<que[tl-1])
        {
            //cout<<'k';
            tl--;
        }
        que[tl]=ar[j]; tl++; j++;
        if(j>=k)pf("%d ",que[hd]);
    }
    pf(NL);
    hd=tl=i=j=0;
    while(j<n)
    {
        if(j-i==k)
        {
            if(que[hd]==ar[i]) hd++;
            i++;
        }
        while(tl>hd&&ar[j]>que[tl-1])
        {
            //cout<<'k';
            tl--;
        }
        que[tl]=ar[j]; tl++; j++;
        if(j>=k)pf("%d ",que[hd]);
    }
    pf(NL);
    return 0;
}


