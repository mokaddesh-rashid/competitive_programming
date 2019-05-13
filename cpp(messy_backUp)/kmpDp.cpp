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
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

string str;
int lps[MAX];

void make_lps(string pattern)
{
    int n = pattern.size();

    lps[0] = lps[1] = 0;
    FOR(i,2,n)
    {
        int p = lps[i-1];
        while(true)
        {
            if(pattern[i - 1] == pattern[p])
            {
                lps[i] = p + 1;
                break;
            }

            if(p == 0) break;
            else p = lps[p];
        }
    }

}

LL dp[205][205][205][2], n, m;

LL rec(int p,int v,int c,int t)
{
    if(p == n && v == 0) return t;
    if(p == n || v < 0) return 0;

    LL &temp = dp[p][v][c][t];

    if(temp != -1) return temp;
    temp = 0;

    if(!t)
    {
        int a;
        for(a = c; str[a] != '(' && a < m; a = lps[a])
            if(a == 0) { a = -1; break;}


        int b;
        for(b = c; str[b] != ')' && b < m; b = lps[b])
            if(b == 0) {b = -1; break;}

       temp = rec(p + 1, v + 1, a + 1, (a + 1 == m) ? 1 : t) +
              rec(p + 1, v - 1, b + 1, (b + 1 == m) ? 1 : t);
    }
    else temp = rec(p + 1, v + 1, c, t) + rec(p + 1, v - 1, c, t);

    return temp % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp, -1);
    int d = 0;

    cin >> n; n += n;
    cin >> str; m = str.size();
    make_lps( str ); ///n size koto golo distinct string r majhe str as a substring ase

    cout << rec(0, 0, 0, 0) << endl;
    return 0;
}
