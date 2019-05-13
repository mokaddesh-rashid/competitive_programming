#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 2005
#define read() freopen("in.txt", "r", stdin)

typedef long long LL;


const LL INF = (1e18);
LL cost[MAX][MAX], n, ara[MAX], k, dp[MAX], bm[MAX];

void compute(int l,int r,int optl,int optr)
{
    if(l > r) return;

    int mid = (l + r)>>1;
    pair<LL,int> best = {INF, -1};

    for(int k = optl; k <= min(mid, optr); k++)
        best = min(best, {dp[k-1] + cost[k][mid], k});

    bm[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

class cmp
{
public:
    bool operator()(int x,int y){ return x > y;}
};

priority_queue<int> lft;
priority_queue<int, vector<int>, cmp> rgt;
LL lft_sum, rgt_sum;

void init()
{
    while(!lft.empty()) lft.pop();
    while(!rgt.empty()) rgt.pop();
    lft_sum = rgt_sum = 0;
}

void add(int v)
{
    lft.push( v ); lft_sum += v;

    while(!rgt.empty() && lft.top() > rgt.top())
    {
        int a = lft.top(); lft.pop(); lft_sum -= a;
        int b = rgt.top(); rgt.pop(); rgt_sum -= b;

        rgt.push( a ); lft.push( b );
        rgt_sum += a; lft_sum += b;
    }

    while(true)
    {
        int a = lft.size(), b = rgt.size();
        if(a - b >= 2)
        {
             int a = lft.top(); lft.pop(); lft_sum -= a;
             rgt.push( a ); rgt_sum += a;
        }
        else break;
    }

    return;
}

int getMedian(){ return lft.top(); }
LL getCost()
{
    int mid = getMedian();

    LL leftNeed = (LL)lft.size() * mid - lft_sum;
    LL rightNeed = rgt_sum - (LL)rgt.size() * mid;

    return rightNeed + leftNeed;
}

int main()
{
    ios::sync_with_stdio(false);
    //read();

    cin >> n >> k;
    FOR(i,1,n) cin >> ara[i];

    FOR(i,1,n)
    {
        init();
        FOR(j,i,n)
        {
            add( ara[j] );
            cost[i][j] = getCost();
        }
    }


    FOR(i,1,n) dp[i] = INF;
    FOR(i,1,k)
    {
        compute(1, n, 1, n);
        FOR(i,0,n) dp[i] = bm[i];
    }
    cout << dp[n] << endl;

    return 0;
}


