#include<bits/stdc++.h>

using namespace std;

#define MAX 1600010
#define MP make_pair
#define PB push_back
#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define F first
#define S second

typedef pair<int,int> PR;
typedef pair<PR, int> PP;

int t, s, p;
PP ara[20], bra[20], val[MAX];

PP getVal(PP v,int mask = 1)
{
    int ab = v.F.F - v.F.S;
    int bc = v.F.S - v.S;
    int ca = v.S - v.F.F;

    return MP( MP(ab * mask, bc * mask), ca * mask);
}

void rec(int p,int a,int b,int c)
{
    if(p == -1)
    {
        val[p++] = getVal( MP( MP(a, b) , c) );
        return;
    }

    rec(p - 1, a + ara[i].F.F, b + ara[i].F.S, c);
    rec(p - 1, a, b + ara[i].F.S, c  + ara[i].S);
    rec(p - 1, a + ara[i].F.F, b, c  + ara[i].S);

    return;
}

void rec(int p,int a,int b,int c)
{
    if(p == -1)
    {
        val[p++] = getVal( MP( MP(a, b) , c), -1);
        return;
    }

    rec(p - 1, a + ara[i].F.F, b + ara[i].F.S, c);
    rec(p - 1, a, b + ara[i].F.S, c  + ara[i].S);
    rec(p - 1, a + ara[i].F.F, b, c  + ara[i].S);

    return;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n;
    m = n/2; n = n - m;

    FOR(i,0,n-1) cin >> ara[i].F.F >> ara[i].F.S >> ara[i].S;
    FOR(i,0,m-1) cin >> bra[i].F.F >> bra[i].F.S >> bra[i].S;



    cout << prin << endl;

    return 0;
}
