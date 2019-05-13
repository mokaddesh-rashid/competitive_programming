#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 200001
#define ba 13
#define LL unsigned long long
typedef pair<LL,LL> PR;

string str;
char coco[MAX];
LL nex[26][MAX], link[26], n, bits[26][MAX];
LL has[2][26][MAX], mul[2][MAX], bag[2][MAX];
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
        bag[ck][i] = modinv(mul[ck][i], M[ck]);
    }
}

void info()
{
    FOR(ck,0,0) ///ck = 0 single hash, c <= 1 for double hash
    {
        dude(ck);
        FOR(i,0,25)
        {
            LL c = 0;
            FOR(j,0,n-1)
            {
                c += (LL)bits[i][j] * mul[ck][j]; ///bits[i][j] represents if i th character presents in jth position /0,1/
                has[ck][i][j] = c;
            }
        }
    }
}

PR ran(LL p,LL l,LL r)
{
    LL ret = has[0][p][r] + M[0];
    if(l) ret -= has[0][p][l - 1]; ret %= M[0];
    ret *= bag[0][l]; ret %= M[0];

    return make_pair(ret, 0);///if single hash

    LL po = has[1][p][r] + M[1];
    if(l) po -= has[1][p][l - 1]; po %= M[1];
    po *= bag[1][l]; po %= M[1];

    return make_pair(ret, po);
}

int main() ///protita character r alada array ase
{
    ios::sync_with_stdio(false);
    ////freopen("in.txt", "r", stdin);
    LL q, x, y, l1, l2, r1, r2, v, p, d, cv;

    cin >> n >> q;
    cin >> str;


    FOR(i,0,25)
    {
        LL p = n;
        REV(j,n-1,0)
        {
            LL x = str[j] - 'a';
            if(x == i) p = j, bits[i][j] = 1;;
            nex[i][j] = p;
        }
    }
    info();


    FOR(t,1,q)
    {
        LL chao = 1;
        memset(link, -1, sizeof(link));

        cin >> l1 >> l2 >> v; l1--; l2--;
        r1 = l1 + v; r1--;
        r2 = l2 + v; r2--;

        FOR(i,0,25)
        {
            x = nex[i][l1];
            d = x - l1;
            y = l2 + d;
            y = str[y] - 'a';

            if(x <= r1 && x < n)
                if(ran(i, l1, r1) != ran(y, l2, r2)) chao = 0;
        }
        if(chao) cout << "YES" << endl;
        else cout << "NO" << endl;


    }

    return 0;
}
