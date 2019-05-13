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
#define MAX 110
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int A[MAX][MAX], B[MAX][MAX], n;

int ver()
{
    int a=n-1;
    FOR(i,0,n-1)
    {
        FOR(j,0,n-1)
        {
            if(A[a][j]!=B[i][j]) return 0;
        }
        a--;
    }

    return 1;
}

int hor()
{

    FOR(i,0,n-1)
    {
        int a=n-1;
        FOR(j,0,n-1)
        {
            if(A[i][a]!=B[i][j]) return 0;
            a--;
        }
    }

    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,m,x=0;

    cin>>n;

    FOR(i,0,n-1)
    FOR(j,0,n-1)cin>>A[i][j];

    FOR(i,0,n-1)
    FOR(j,0,n-1)cin>>B[i][j];

    x=ver();
    x=max(x,hor());

    cout<<x<<NL;
    return 0;
}


