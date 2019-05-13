#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define LL           long long
#define PB push_back
#define MAX 1010
#define F first
#define S second
#define MP make_pair
#define PR pair<int,int>

LL dp[(1<<18)][101], n, m;
LL v[22], gigi;
string str;

LL rec(int mask,int r)
{
    ///cout << mask << ' ' << r << endl;
    if(mask == (1<<n) - 1) return (r == 0);

    LL &temp = dp[mask][r];
    if(temp != -1) return temp;

    int can[10], p = 0;
    FOR(i,0,9) can[i] = -1;

    FOR(i,0,n-1)
    {
        if(mask & (1<<i))
        {
            p++;
            continue;
        }
        int c = str[i] - '0';
        can[c] = i;
    }

    temp = 0;
    FOR(i,0,9)
    {
        if(!mask && !i) continue;
        if(can[i] == -1) continue;

        LL newMask = mask | (1<<can[i]), nr = (r + (i * v[p])) % m;
        temp += rec(newMask, nr);
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> str >> m; n = str.size();
    REV(i,str.size() - 1, 0)
    {
        if(i == str.size() - 1) v[i] = 1;
        else v[i] = v[i + 1] * 10;
    }

    mem(dp, -1);
    cout << rec(0, 0) << endl;

    return 0;

}
