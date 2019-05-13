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
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          100000007
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int ar[100], mat[102][100001];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        //mem(mat,0);
        int i, j, x=0, y, n, m, a;
        cin>>n>>m;
        FOR(i,1,n) cin>>ar[i];
        FOR(i,1,n) mat[i][0]=1;

        FOR(i,1,m)
        {
            FOR(j,1,n)
            {
                a=i-ar[j];
                //cout<<j<<' '<<i<<' '<<a<<endl;
                if(a>=0) mat[j][i]=mat[j-1][i]+mat[j][a];
                else mat[j][i]=mat[j-1][i];
                mat[j][i]%=mod;
                //cout<<mat[j][i]<<endl;
            }
            //cout<<endl;
        }
        FOR(i,1,m) if(mat[n][i]!=0) x++;
        cout<<"Case "<<t<<": "<<x<<endl;//cout<<mat[n][m]<<endl;
    }
    return 0;
}


