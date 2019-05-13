#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define LL long long
#define FOR(i,j,k) for(LL i=j; i<=k; i++)
#define MAX 500010

struct PR
{
    LL first, second;
};

PR MP(int x,int y)
{
    PR ret = {x,y};
    return ret;
}

class Compare
{
public:
    bool operator()(PR x,PR y)
    {
        return x.F > y.F;
    }
};
priority_queue<PR,vector<PR>,Compare> que;

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);

    que.push( MP(0, 0) );



    return 0;
}
