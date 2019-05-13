#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i = j; i <= k; i++)
const int MAX = 300010;
typedef long long LL;

int sfx[20][MAX], ara[MAX], n, go[MAX], rev[MAX];

int maax(int x,int y) {return ara[x] >= ara[y] ? x : y;}
void preCal()
{
    for(int i = 0; i < n; i++) sfx[0][i] = i;

    for(int l = 1; l < 20; l++)
    for(int i = 0; i < n; i++)
        if(i + (1<<(l - 1)) < n)
            sfx[l][i] = maax(sfx[l - 1][i], sfx[l - 1][i + (1<<(l - 1))]);

    int p = 0, t = 0;
    while(p < MAX)
    {
        for(; p < (1<<(t + 1)) && p < MAX; p++) go[p] = t;
        t++;
    }
}

int query(int l,int r)
{
    int jump = go[(r - l) + 1]; r = r - ((1<<jump) - 1);
    return maax(sfx[jump][l], sfx[jump][r]);
}

LL divide(int b,int e)
{
    if(b >= e) return 0;

    int m = query(b, e), nx, ny, l, r;
    LL ret = 0;

    if(abs(m - b) > abs(e - m)) nx = b, ny = m - 1, l = m, r = e;
    else l = b, r = m, nx = m + 1, ny = e;

    FOR(i,l,r)
    {
        int nd = ara[m] - ara[i];
        if(nd > 0 && nx <= rev[nd] && rev[nd] <= ny) ret++;
    }

    return ret + divide(b, m - 1) + divide(m + 1, e);
}

int rec(int l,int r)
{
    if(l > r) return 0;
    return max(ara[l], rec(l + 1, r));
}

int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ara[i]), rev[ ara[i] ] = i;
    preCal();
    cout << divide(0, n-1) << endl;

//    int cnt = 0;
//    FOR(i,0,n-1)
//        FOR(j,i,n-1)
//            if(ara[i] + ara[j] == rec(i, j)) cnt++;
//    cout << cnt << endl;
    return 0;
}
