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

LL ar[MAX], n, k, vo, shit, p, ok;
class Compare
{
public:
    bool operator()(PR x,PR y)
    {
        return x.F > y.F;
    }
};
priority_queue<PR,vector<PR>,Compare> que;
LL mat[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    LL st = 0, en = 0, mid, mo;

    cin >> n >> k;
    FOR(i,0,n-1)
    {
        cin >> ar[i];
        if(ar[i] < 0) vo += ar[i];
        ar[i] = abs( ar[i] );
    }
    sort(ar, ar + n);

    que.push( MP(ar[0], 0) );
    cout << vo << endl;
    FOR(i,0,k-2)
    {
        PR use = que.top(); que.pop();
        cout << vo + use.F << endl;

        if(use.S + 1 < n)
        {
            que.push( MP(use.F + ar[use.S + 1], use.S + 1) );
            que.push( MP(use.F - ar[use.S] + ar[use.S + 1], use.S + 1) );
        }
    }



    return 0;
}
