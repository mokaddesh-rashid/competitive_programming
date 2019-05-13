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
int k, a, b, dp[210][210];

int rec(int p,int k)
{
    if(p == 0 && k == 0) return 1;
    if(p <= 0 || k < 0) return 0;


    int &temp = dp[p][k];
    if(temp != -1) return temp;

    FOR(i,a,b) temp = max(temp, rec(p - i, k - 1));
    return temp;

}

void prin(int p,int k)
{
    if(p == 0 && k == 0) return;
    if(p <= 0 || k < 0) return;

    FOR(i,a,b)
    {
        if( rec(p - i, k - 1) )
        {
            prin(p - i, k - 1);
            FOR(j,p-i,p-1) cout << str[j];
            cout << endl;
            return;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> k >> a >> b;
    cin >> str;

    mem(dp, -1);
    if(rec(str.size(), k)) prin(str.size(), k);
    else cout << "No solution" << endl;

    return 0;
}