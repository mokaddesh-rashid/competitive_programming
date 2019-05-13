#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 1000001
#define ba 31
#define LL unsigned long long
typedef pair<LL,LL> PR;

string str;
char coco[MAX];
LL nex[26][MAX], link[26], n, bits[MAX];
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

PR ran(LL l,LL r)
{
    LL ret = has[0][r] + M[0];
    if(l) ret -= has[0][l - 1]; ret %= M[0];
    ret *= bag[0][l]; ret %= M[0];

    LL po = has[1][r] + M[1];
    if(l) po -= has[1][l - 1]; po %= M[1];
    po *= bag[1][l]; po %= M[1];

    return make_pair(ret, po);
}

PR hashVal(string str)
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
    return ret;
}

LL ohoh[2001*2001], tp;
int main()
{
    ios::sync_with_stdio(false);
   // freopen("in.txt", "r", stdin);
    LL q, x, l, r, m, o;
    string pre, suf;

    cin >> str; n = str.size();
    cin >> pre >> suf; m = pre.size(); o = suf.size();


    FOR(i,0,n-1)
    {
        LL x = str[i] - 'a'; x++;
        bits[i] = x;
    }
    info();

    PR po = hashVal( pre ), so = hashVal( suf );

    FOR(i,0,n-1)
    {
        FOR(j,i,n-1)
        {
            if(i + m - 1 <= j && j - o + 1 >= i && po == ran(i, i + m - 1) && so == ran(j - o + 1, j))
            {
                PR use = ran(i, j);
                ohoh[tp] = (LL)use.F * 1000000000 + use.S;
                tp++;
            }
        }
    }

    sort(ohoh, ohoh + tp);
    int prin = 0;

    if(tp)
    FOR(i,0,tp-1)
    {
        if(i == 0 || ohoh[i] != ohoh[i - 1]) prin++;
    }
    cout << prin << endl;

    return 0;
}
