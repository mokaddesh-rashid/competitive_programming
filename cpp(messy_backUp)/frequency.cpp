#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 1010
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

PR reverseRan(int l,int r)
{
    return ran(n - r - 1, n - l - 1);
}

int isPalin(int l,int r)
{
    if(ran(l, r) == reverseRan(l, r)) return 1;
    return 0;
}

PR ara[MAX * MAX];
int cou;
int show;

int getBig(PR x,PR y)
{
    int Xen = (x.S - x.F) + 1;
    int Yen = (y.S - y.F) + 1;
    int len = min(Xen, Yen);
    int st = 0, en = len, mid, koto = 0;

    while(st <= en)
    {
        mid = (st + en)>>1;
        if(ran(x.F, x.F + mid - 1) == ran(y.F, y.F + mid - 1) ) st = mid + 1, koto = max(mid, koto);
        else en = mid - 1;
    }

    if(len == koto) return (Xen <= Yen) ? 1 : 0;
    else return (str[x.F + koto] < str[y.F + koto]) ? 1 : 0;
}

class cmp
{
    public:
        bool operator()(int x,int y)
        {
            int v = getBig(ara[x], ara[y]);
            return v;
        }
};

int id[MAX * MAX];

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);

        int l, r, x, q;
        char ch;

       /// cin >> n >> q;
        cin >> str; pre = str; reverse(pre.begin(), pre.end());
        str += pre;

        n = str.size(); m = n / 2;

        FOR(i,0,n-1)
        {
            LL x = str[i] - 'a'; x++;
            bits[i] = x;
        }
        info();

        cou = 0;
        FOR(i,0,m-1)
            FOR(j,i,m-1)
                if(isPalin(i, j)) id[cou] = cou, ara[cou++] = make_pair(i, j);
        sort(id, id + cou, cmp());

        FOR(i,0,cou-1)
        {
            int p = id[i];
            FOR(j,ara[p].F,ara[p].S) cout << str[j];
            cout << p << endl;
        }


    return 0;
}


