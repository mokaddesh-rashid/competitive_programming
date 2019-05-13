#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 2000001
#define ba 31
#define LL unsigned long long
typedef pair<LL,LL> PR;

string str;
LL n, bits[MAX];
LL has[2][MAX], mul[2][MAX], bag[2][MAX];
LL M[] = {1000000007, 141650939};
LL bm(LL n, LL p, LL m)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % m;

    LL ret = bm(n, p/2, m);
    ret = (ret * ret) % m;
    if(p % 2) ret = (ret * n) % m;
    return ret%m;
}

LL modinv( LL n, LL p )
{
    return bm( n, p-2, p );
}

void dude(int ck)
{
    mul[ck][0] = 1;
    bag[ck][0] = modinv(mul[ck][0], M[ck]);
    FOR(i,1,n-1)
    {
        mul[ck][i] = mul[ck][i - 1] * ba;
        mul[ck][i] %= M[ck];
        if(i == 1) bag[ck][i] = modinv(mul[ck][i], M[ck]);
        else  bag[ck][i] = (bag[ck][i-1] * bag[ck][1]) % M[ck];
    }
}

void info()
{
    FOR(ck,0,1)
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

LL ran(LL l,LL r)
{
    LL ret = has[0][r] + M[0];
    if(l) ret -= has[0][l - 1]; ret %= M[0];
    ret *= bag[0][l]; ret %= M[0];

    LL po = has[1][r] + M[1];
    if(l) po -= has[1][l - 1]; po %= M[1];
    po *= bag[1][l]; po %= M[1];

    return ret * 1000000000 + po;
}

LL hashVal(string str)
{
    PR ret;
    int n = str.size();

    FOR(ck,0,1)
    {
        LL c = 0;
        FOR(j,0,n-1)
        {
            LL v = str[j] - 'a'; v++;
            c += (LL)v * mul[ck][j]; ///age info call naah hole mul[][] always 0 thakbe
            c %= M[ck];
        }
        if(!ck) ret.F = c;
        else ret.S = c;
    }
    return ret.F * 1000000000 + ret.S;
}

set<LL> sota;
map<LL,int> mopa;
int cnt[MAX], s, k, sz, m;
string pre;

int rec(int p)
{
    LL val = ran(p, p + k - 1);

    if(cnt[p] != -1) return cnt[p];
    if(p >= n) return 0;
    if(sota.find(val) == sota.end()) return 0;

    sota.erase(sota.find(val));
    cnt[p] = 1 + rec(p + k);
    sota.insert(val);

    return cnt[p];
}

void prin(int p,int l)
{
    LL val = ran(p, p + k - 1);
    if(!l) return;
    cout << mopa[val] << ' ';
    prin(p + k, l - 1);

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    int n = sqrt(500000);
    cout << n;
    return 0;
}
