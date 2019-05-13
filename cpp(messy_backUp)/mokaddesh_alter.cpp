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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL in[MAX], sum[MAX], Xor[MAX], val[MAX];
vector<int>mat[MAX];

void dfs(int p,int pa)
{
    sum[p]=Xor[p]=val[p];
    in[p]=0;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];

        if(x!=pa)
        {
            dfs(x,p);
            sum[p]+=sum[x];
            Xor[p]=Xor[p]^Xor[x];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;
    cin>>tc;

    FOR(tt,1,tc)
    {

        clean(mat,MAX-1);
        LL i,j,n,m,a,b,c,p,x,y;
        pr ck,ans;

        cin>>n;

        FOR(i,1,n)cin>>val[i];
        FOR(i,1,n-1)
        {
            cin>>a>>b;
            a++; b++;
            mat[a].PB(b);
            mat[b].PB(a);
            in[a]++;
            in[b]++;
        }

        FOR(i,1,n)
        {
            if(in[i]==1)
            {
                p=i;
                dfs(p,p);
                break;
            }
        }
        ///cout<<NL;

        ans.F=maxx; ans.S=0;
        FOR(i,1,n)
        {
            if(p!=i)
            {
                x=Xor[p]^Xor[i]; y=Xor[i];

                ck.F=abs(x-y); ck.S=x+y;

                if(ans.F>ck.F)ans.F=ck.F, ans.S=ck.S;
                else if(ans.F==ck.F&&ans.S<ck.S) ans.S=ck.S;
               /// cout<<i<<NL;
               /// cout<<ck.F<<' '<<ck.S<<' '<<sum[i]<<' '<<a<<' '<<x<<' '<<y<<' '<<val[i]<<NL;

            }
        }
        ///cout<<NL;
        ///cout<<sum[p]<<' '<<Xor[p]<<' '<<p<<NL;

        cout<<ans.F<<' '<<ans.S<<NL;
    }
    return 0;
}



