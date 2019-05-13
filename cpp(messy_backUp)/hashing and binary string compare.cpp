#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;
typedef pair<string,int> SOT;

string str;
const int ba = 5;
int n;
LL bits[MAX];
LL has[2][MAX], mul[2][MAX], bag[2][MAX];
LL M[] = {1000000007, 141650939};
LL MI[] = {400000003, 28330188};

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

LL ran(LL l,LL r)
{
    LL ret = has[0][r] + M[0];

    if(l) ret -= has[0][l - 1]; ret %= M[0];
    ret *= bag[0][l]; ret %= M[0];

    return ret;
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

int id[MAX];

void mergeIt(int b, int e, int l, int r)
{
    int p = b;
    if(finB(id[l], id[b])) id[p] = id[l];
}

void divide(int st, int en)
{
    if(st < en)
    {
        int mid = (st + en)>>1;

        divide(st, mid);
        divide(mid + 1, en);

        mergeIt(st, mid, mid + 1, en);
    }
    return;
}

int rec(int p)
{
    if(p == n) return n;

    if(str[p] == '0') return rec(p + 1);
    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int u, v, p = 0;

    cin >> n;
    cin >> str;

    FOR(i,0,n-1) bits[i] = (str[i] - '0') + 1;
    info();

    FOR(i,0,n-1)
    {
        if(str[i] == '0')
        {
            cout << i << ' ';

            FOR(j,i,n-1) id[p++] = j;
            divide(0, p-1);

            cout << id[0] - i << endl;
            return 0;
        }
    }
    cout << "0 0" << endl;

    return 0;
}
