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

    LL po = has[1][r] + M[1];
    if(l) po -= has[1][l - 1]; po %= M[1];
    po *= bag[1][l]; po %= M[1];

    return ret*(LL)1000000000 + po;
}

int dp[8001][8001];
int dope[8001], prime[8002];
bool mess[MAX][MAX];

int getVal(int a,int b)
{
    int ret = b;
    while(a)
    {
        ret++;
        a /= 10;
    }
    return ret;
}

void up(int Root,int p,int l,int val)
{
    if(p + l > n) return;

    if(ran(Root, Root + l - 1) == ran(p, p + l - 1))
    {
        int &temp = dp[Root][p + l];
        temp = min(temp, getVal(val, l));

        up(Root, p + l, l, val + 1);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int l, r;

    cin >> str; n = str.size();
    cout << str[92] <<endl;
//    FOR(i,0,n-1)
//    {
//        LL x = str[i] - 'a'; x++;
//        bits[i] = x;
//    }
//    info();
//
//    FOR(i,0,n)
//    FOR(j,0,n)
//    if(i == j) dp[i][j] = 2;
//    else dp[i][j] = 80008;
//
//    FOR(i,0,n-1)
//        FOR(l,2,n)
//        {
//            if(!mess[i][l]) up(i, i, l, 1);
//        }
//
//    FOR(i,0,n) dope[i] = 8008;
//    dope[0] = 0;
//
//    FOR(i,0,n-1)
//        FOR(l,0,n)
//        {
//            if(i + l <= n)
//                dope[i + l] = min(dope[i + l], dope[i] + dp[i][i + l]);
//        }
//    cout << dope[n] << endl;

    return 0;
}
