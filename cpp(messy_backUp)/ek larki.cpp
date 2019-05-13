#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define MP make_pair

typedef pair<int,int> pii;
typedef long long LL;

const int MAXM = 260, MAX = (1e5) + 5;

int dp[MAXM][MAXM][MAXM], n, nex[MAX][27];
string str;

void preCal()
{
    FOR(i,0,25)
    FOR(j,0,MAX-1) nex[j][i] = MAX - 4;

    for(int i = 'a', c = 0; i <= 'z'; i++, c++)
    {
        int lp = MAX - 4;
        for(int p = n - 1; p >= 0; p--)
        {
            nex[p + 1][c] = lp;
            if((int)str[p] == i) lp = p + 1;
        }
        nex[0][c] = lp;
    }
}

string A[3];
int id(char ch) {return ch - 'a';}

void update(int a,int b,int c)
{
    int &t = dp[a][b][c];
    if(a || b || c) t = MAX;
   /// cout << t << " = " << a << ' ' << b << ' ' << c << " = ";
    if(a) t = min(nex[ dp[a - 1][b][c] ][ id(A[0][a - 1]) ], t);
    if(b) t = min(nex[ dp[a][b - 1][c] ][ id(A[1][b - 1]) ], t);
    if(c) t = min(nex[ dp[a][b][c - 1] ][ id(A[2][c - 1]) ], t);
   /// cout << t << endl;
   /// if(a == 3 && b == 2 && c == 2) cout << nex[ dp[a][b][c - 1] ][ id(A[2][c - 1]) ] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int q, ty;
    char ch;

    cin >> n >> q >> str;
    preCal();

    int r0, r1, r2, l0, l1, l2;
    FOR(oo,0,q-1)
    {
        cin >> ch >> ty; ty--;

        if(ch == '+')
        {
            cin >> ch;
            A[ty] = A[ty] + ch;

            r0 = A[0].size(); r1 = A[1].size(); r2 = A[2].size();
            l0 = ty == 0 ? r0 : 0;
            l1 = ty == 1 ? r1 : 0;
            l2 = ty == 2 ? r2 : 0;

            FOR(p0,l0,r0)
            FOR(p1,l1,r1)
            FOR(p2,l2,r2) update(p0, p1, p2);
        }
        else
        {
            A[ty].pop_back();
        }
        r0 = A[0].size(); r1 = A[1].size(); r2 = A[2].size();
        cout << ((dp[r0][r1][r2] <= n) ? "YES" : "NO") << "\n";
    }
    return 0;
}
