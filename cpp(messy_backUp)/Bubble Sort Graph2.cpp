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
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define LL long long
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


LL ar[100010];
struct info
{
   LL sum;

}tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum = v;
}

LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return max(lft,rgt);
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = max(tree[lnd].sum,tree[rnd].sum);
}


int main()
{

    LL n, m, i, x, y, c = 0, a = 1, b;
    int cr[100010], bs[100010];

    sf(n);
    FOR(i,0,n-1) sf(ar[i]);
    REV(i,n-1,0)
    {
        a = ar[i];
        x = query(1,1,100001,a+1,100001);
        c=max(c,x+1);
        update(1,1,100001,ar[i],ar[i],x+1);
    }

    pf("%lld\n",c);
    return 0;
}



