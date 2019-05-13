#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 200001
#define ba 31
#define LL unsigned long long
typedef pair<LL,LL> PR;

string str, pre;
LL n, bits[MAX], m;
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


PR reverseRan(int l,int r)
{
    return ran(n - r - 1, n - l - 1);
}

int isPalin(int l,int r)
{
    if(ran(l, r) == reverseRan(l, r)) return 1;
    return 0;
}

int centerPoint(int p1,int p2)
{
    int st = 0, en = min(p1, (int)m - (p2 + 1)), mid;

    while(st <= en)
    {
        mid = (st + en)>>1;
        if(isPalin(p1 - mid, p2 + mid)) st = mid + 1;
        else en = mid - 1;
    }

    if(p1 == p2) return 2*st - 1;
    else return 2*st;
}

int finB(int l,int x)///purata match
{
    int en = n - max(l, x), st = 1, mid, val = 0;

    while(st <= en)
    {
        mid = (st + en)>>1;
        if(ran(l, l + mid - 1) == ran(x, x + mid - 1)) st = mid + 1, val = max(val, mid);
        else en = mid - 1;
    }

    if(x + val == n) return 1;
    if(l + val == n) return 0;

    return str[l + val] > str[x + val];
}

int cnt[MAX];

int main()
{
    ios::sync_with_stdio(false);
   // freopen("in.txt", "r", stdin);
    int l, r, x;

   /// cin >> n;
    cin >> str; pre = str; reverse(pre.begin(), pre.end());
    str += pre;

    n = str.size(); m = n / 2;
    ///cout << str << endl;
    FOR(i,0,n-1)
    {
        LL x = str[i] - 'a'; x++;
        bits[i] = x;
    }
    info();

    int prin = 0, pos;
    FOR(i,0,m-1)
    {
        x = centerPoint(i, i);
        int st = (i - x/2);
        cnt[st] = max(cnt[st], x);

        if(i < m - 1)
        {
            x = centerPoint(i, i + 1);
            st = (i - x/2) + 1;
            cnt[st] = max(cnt[st], x);
            ////cout << i << ' ' << x << ' ' << st << endl;
        }
    }
    FOR(i,0,m-1)
    {
        if(cnt[i] > prin) prin = cnt[i], pos = i;
    }
    cout << prin << endl;
    FOR(i,pos,pos+prin-1) cout << str[i];

    return 0;
}

