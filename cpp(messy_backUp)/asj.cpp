#include<bits/stdc++.h>
#pragma GCC optimize ("O3")

using namespace std;

#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX (int)2e6 + 10
#define F first
#define S second


typedef pair<int,int> PR;

int uni[MAX], pa[MAX], p, sz[MAX];
bool has[MAX];
stack<int> stk;

void initDsu() { FOR(i,0,MAX-1) pa[i] = i, has[i] = 0, sz[i] = 1;}
int finPa(int p)
{
    for(;pa[p] != p;p = pa[p])
    {
        stk.push( p );
    }
    while(!stk.empty())
    {
        int top = stk.top(); stk.pop();
        pa[top] = p;
    }

    return p;
}


PR ara[MAX], in[MAX];

int main()
{
    int n, c = 0;

    sf(n);

    p = 1;
    FOR(i,0,n-1)
        sff(ara[i].F, ara[i].S),
        uni[p++] = ara[i].F, uni[p++] = ara[i].S;
    sort(uni, uni + p);

    FOR(i,0,n-1)
    {
        int u = ara[i].F, v = ara[i].S;

        u = lower_bound(uni, uni + p, u) - uni;
        v = lower_bound(uni, uni + p, v) - uni;

        in[i] = make_pair(u, v);
    }

    int st = 0, en = p - 1, mid, show = -1;

    while(st <= en)
    {
        mid = (st + en)>>1;

        initDsu(); c = 0; has[0] = 1;

        FOR(i,0,n-1)
        {
            int u = ara[i].F, v = ara[i].S;

            if(u > uni[mid]) u = 0;
            else u = in[i].F;

            if(v > uni[mid]) v = 0;
            else v = in[i].S;

            int r1 = finPa( u ), r2 = finPa( v );

            if(!(has[r1] && has[r2]) )
            {
               c++;
               if(sz[r1] < sz[r2]) swap(r1, r2);

               if(r1 != r2) has[r1] |= has[r2];
               else has[r1] = 1;

               pa[r2] = r1;
               sz[r1] += sz[r2];
            }

        }
       // cout << c << endl << endl;

        if(c == n) en = mid - 1, show = show == -1 ? uni[mid] : min(show, uni[mid]);
        else st = mid + 1;

    }

    cout << show << endl;

    return 0;
}
