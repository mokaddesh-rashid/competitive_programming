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
#define sz 200010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<int> mat[sz];
int cnt[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c=0,x,y,z,l,k;

    cin>>n>>m;
    FOR(i,0,m-1)
    {
        cin>>x>>l>>k;
        a=max(1,x-k);
        b=x+k+1;
        ///cout<<a<<' '<<b<<NL;
        mat[a].PB(l);
        mat[b].PB(l*-1);
    }

    a=0;
    FOR(i,1,n)
    {
        FOR(j,0,(int)mat[i].size()-1)
        {
            x=mat[i][j];
            if(x<0)
            {
                x=x*-1;
                cnt[x]--;
                if(cnt[x]==1) c++;

            }
            else
            {
               cnt[x]++;
               if(cnt[x]==1) c++;
               else if(cnt[x]==2) c--;
            }
        }
        FOR(l,1,15) cout<<cnt[l]<<' ';
        cout<<NL;
        if(c>0) a++;
    }

    cout<<a<<NL;
    return 0;
}


