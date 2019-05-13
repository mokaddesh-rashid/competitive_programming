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
#define M          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int dp[52][33][33][2][2], n, col;
LL prin;
string str, strL, strR;

int rec(int p,int v3,int v6,int t,int ok)
{
    if(p == 51) return (v3 == 16 && v6 == 16 && ok);
    if(max(v3, v6) > 32 || min(v3, v6) < 0) return 0;

    int &temp = dp[p][v3][v6][t][ok];

    if(temp != -1 && t) return temp;
    temp = 0;

    int l = 0, r = 9;
    if(!t) r = str[p] - '0';
    FOR(i,0,r)
    {
        int n3 = v3 + (i == 3), n6 = v6 + (i == 6);
        if(i == 9) n3--, n6--;
        temp += rec(p + 1, n3, n6, i == r ? t : 1, (i == 3) ? 1 : ok);
        temp %= M;
    }

    return temp;
}

int getVal(string v)
{
    str = v;
    while(str.size() < 51){str = "0" + str;}
    return rec(0, 16, 16, 0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp, -1);
    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
        cin >> strL >> strR;
        prin = getVal( strR );
        REV(i,(int) strL.size() - 1,0)
        {
            if(strL[i] != 0)
            {
                char ch = strL[i]; ch--;
                strL[i] = ch;
                break;
            }
        }
        prin += M; prin -= getVal( strL );
        cout << (prin % M) << endl;
    }
    return 0;
}

