#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX 5005
#define F first
#define S second
#define MP make_pair

typedef pair<int,int> PR;

int dp[MAX][MAX][2], n;
PR ara[MAX];

int rec(int p,int x,int t)
{
    if(p == n+1) return 0;

    int &temp = dp[p][x][t], ret, add;
    if(temp != -1) return temp;

    temp = 1e9;
    if(t == 0) add = ara[x].F;
    else add = ara[x].S;

    FOR(i,x + 1,n)
    {
        ret = rec(p, i, 0);
        ret += abs(ara[i].F - add);
        temp = min(temp, ret);

        ret = rec(p, i, 1);
        ret += abs(ara[i].S - add);
        temp = min(temp, ret);
    }

    ret = rec(p + 1, x, t);
    if(ara[p].F <= add && add <= ara[p].S);
    else ret += min(abs(ara[p].F - add), abs(ara[p].S - add));

    temp = min(temp, ret);

    return temp;

}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
    int a, l, r;

    cin >> n >> a;

    ara[0] = MP(a, a);
    FOR(i,1,n)
       cin >> ara[i].F >> ara[i].S;

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;


    return 0;
}
