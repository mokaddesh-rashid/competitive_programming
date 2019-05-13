#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i = j; i <= k; i++)
const int MAX = 1000010;
typedef long long LL;

int sfx[2][20][MAX], ara[MAX], n, go[MAX];

int maax(int x,int y) {return ara[x] >= ara[y] ? x : y;}
int miin(int x,int y) {return ara[x] <= ara[y] ? x : y;}

void preCal()
{
    for(int i = 0; i < n; i++) sfx[1][0][i] = sfx[0][0][i] = i;

    for(int l = 1; l < 20; l++)
    for(int i = 0; i < n; i++)
        if(i + (1<<(l - 1)) < n)
        {
            sfx[0][l][i] = maax(sfx[0][l - 1][i], sfx[0][l - 1][i + (1<<(l - 1))]);
            sfx[1][l][i] = miin(sfx[1][l - 1][i], sfx[1][l - 1][i + (1<<(l - 1))]);
        }

    int p = 0, t = 0;
    while(p < MAX)
    {
        for(; p < (1<<(t + 1)) && p < MAX; p++) go[p] = t;
        t++;
    }
}

int query(int l,int r,int ty)
{
    int jump = go[(r - l) + 1]; r = r - ((1<<jump) - 1);

    if(ty) return miin(sfx[ty][jump][l], sfx[ty][jump][r]);
    else return maax(sfx[ty][jump][l], sfx[ty][jump][r]);
}

LL divide(int b,int e,int ty)
{
    if(b >= e) return 0;

    int m = query(b, e, ty);
    LL lf = m - b, rg = e - m, ret;

    ret = lf * rg + lf + rg; ret = ret * (LL)ara[m];

    return ret + divide(b, m - 1, ty) + divide(m + 1, e, ty);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &ara[i]);
    preCal();
    cout << divide(0, n-1, 0) - divide(0, n-1, 1) << endl;

    return 0;
}

