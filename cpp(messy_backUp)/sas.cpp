#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 8010
#define ba 31
#define LL unsigned long long
typedef pair<LL,LL> PR;

string str;
char coco[MAX];

LL n, bits[MAX];
LL has[2][MAX], mul[2][MAX], bag[2][MAX];

LL M[] = {1000000007, 141650939};
LL MI[] = {129032259, 105095858};

void dude(int ck)
{
    mul[ck][0] = bag[ck][0] = 1;
    FOR(i,1,n-1)
    {
        mul[ck][i] = mul[ck][i - 1] * ba;
        mul[ck][i] %= M[ck];
        if(i == 1) bag[ck][i] = MI[ck];
        else  bag[ck][i] = (bag[ck][i-1] * bag[ck][1]) % M[ck];
    }
}

void info()
{
    FOR(ck,0,0)
    {
        dude(ck);
        LL c = 0;
        FOR(j,0,n-1)
        {
            c += (LL)bits[j] * mul[ck][j];
            c %= M[ck];
            has[ck][j] = c;
        }
    }
}

LL ran(int l,int r)
{
    LL ret = has[0][r] + M[0];
    if(l) ret -= has[0][l - 1]; ret %= M[0];
    ret *= bag[0][l]; ret %= M[0];
    return ret;

}

int dp[MAX][MAX], cost[MAX][MAX];
int dope[MAX];

int getVal(int a)
{
    int ret = 0;
    while(a)
    {
        ret++;
        a /= 10;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
    int l, r, p = 0;

    cin >> str; n = str.size();
    FOR(i,0,n-1)
    {
        LL x = str[i] - 'a'; x++;
        bits[i] = x;
    }
    info();

    FOR(i,0,n-1)
        FOR(j,1,n)
            if(i + j <= n) dp[i][j] = i + j;

    REV(i,n-1,0)
    {
        REV(l,n,1)
        {
            int x = i, y = i + l;
            if(y + l <= n && ran(x, y - 1) == ran(y, y + l - 1))
                dp[x][l] = dp[y][l];
        }
    }

    FOR(i,0,n-1)
        FOR(j,0,n) cost[i][j] = n + 1;

    FOR(i,0,n-1)
    {
        FOR(j,1,n)
        {
            int v = dp[i][j], val = 1;

            FOR(k,i + j,v)
            {
                if(cost[i][k] < j + getVal( val )) break;
                else cost[i][k] = j + getVal( val );
                val++;
            }
        }
    }

    FOR(i,0,n) dope[i] = n + 1;
    dope[0] = 0; dope[n] = n + 1;

    FOR(i,0,n-1)
        FOR(l,0,n)
        {
            if(i + l <= n)
                dope[i + l] = min(dope[i + l], dope[i] + cost[i][i + l] );
        }

    cout << dope[n] << endl;

    return 0;
}
