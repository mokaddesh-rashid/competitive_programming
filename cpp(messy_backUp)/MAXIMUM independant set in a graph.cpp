#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX ((1<<20) + 10)

int lft[45], rgt[45], n, k, mid, val[MAX], dp[21][MAX];

int add(int p,int pos)
{
    if(pos < mid) lft[p] |= (1 << pos);
    else rgt[p] |= (1 << (pos - mid));
}

int rec(int p,int mask)
{
    if(p == -1) return val[mask];

    int &temp = dp[p][mask];
    if(temp != -1) return temp;

    temp = 0;
    int newMask = mask ^ (1<<p);

    if(mask & (1<<p)) temp = max(temp, rec(p - 1, newMask));
    temp = max(temp, rec(p - 1, mask));

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);

    int u, v;

    cin >> n >> k; mid = n/2;

    FOR(i,0,n-1) add(i, i);

    FOR(i,0,n-1)
    {
        FOR(j,0,n-1)
        {
            int c;
            cin >> c;
            if(c || i == j) add(i, j);
        }
    }


    int x = mid, y = n - mid, prin = 0;

    FOR(i,1,(1<<x) - 1)
    {
        int highBit = (1<<x) - 1;
        int c = 0;

        FOR(j,0,x-1)
            if(i & (1<<j)) highBit &= lft[j], c++;

        if((i & highBit) == i) val[i] = c, prin = max(prin, c);
    }

    memset(dp, -1, sizeof(dp));
    FOR(i,1,(1<<y) - 1)
    {
        int highBit = (1<<y) - 1;
        int c = 0;

        FOR(j,0,y-1)
            if(i & (1<<j)) highBit &= rgt[x + j], c++;

        if((i & highBit) == i)
        {
            int cry = (1<<x) - 1;

            FOR(j,0,y-1)
                if(i & (1<<j)) cry &= lft[x + j];

            prin = max(prin, c + rec(x - 1, cry));

        }
    }


    return 0;
}
