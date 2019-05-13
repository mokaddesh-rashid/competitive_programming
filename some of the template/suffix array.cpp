#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 1000010

struct PR
{
    int f, s, p;
};

class Compare
{
public:
    bool operator()(PR x,PR y)
    {
        if(x.f == y.f) return x.s < y.s;
        else return x.f < y.f;
    }
};

int sfx[21][MAX];
string str;
PR ar[MAX];

bool same(PR p,PR t)
{
    if(p.f == t.f && p.s == t.s) return 1;
    else return 0;
}

void sortSuffix(string str)
{
    int n = str.size();

    FOR(i,0,n-1) sfx[0][i] = str[i];

    FOR(i,1,20)
    {
        int x = 1<<(i - 1);
        FOR(j,0,n-1)
        {
            ar[j].f = sfx[i - 1][j];
            ar[j].s = -1;
            ar[j].p = j;

            if(j + x < n) ar[j].s = sfx[i - 1][j + x];
        }
        sort(ar, ar + n, Compare());

        int p = 0;
        FOR(j,0,n-1)
        {
            if(j != 0) if( !same(ar[j], ar[j - 1]) )p++;
            sfx[i][ ar[j].p ] = p;
        }
    }

    FOR(i,0,n-1) cout << ar[i].p << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    cin >> str;
    sortSuffix( str );

    return 0;
}
