
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
#define MAX 1010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


int dp[MAX][MAX],ar[MAX],t,n;
map<int,int>mopa;

int rec(int x,int y)
{
    int a,b,c,d=x+y,temp=0;

    if(mopa[d]>0)
    {
        //cout<<d<<' ';
        mopa[d]--;
        temp=1+rec(y,d);
        mopa[d]++;
    }
    return temp;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,m,a,b,c=0;

    cin>>n;
    FOR(i,0,n-1)cin>>ar[i],mopa[ar[i]]++;

    c=mopa[0];
    FOR(i,0,n-1)
    {
        FOR(j,0,n-1)
        {
            if(i==j)continue;
            else
            {
                mopa[ar[i]]--;mopa[ar[j]]--;
                ///cout<<ar[i]<<' '<<ar[j]<<' ';
                if(!(ar[i]==0&&ar[j]==0)) c=max(c,rec(ar[i],ar[j])+2);
                mopa[ar[i]]++;mopa[ar[j]]++;
                ///cout<<NL;
            }
        }
    }

    cout<<c<<NL;
    return 0;
}

