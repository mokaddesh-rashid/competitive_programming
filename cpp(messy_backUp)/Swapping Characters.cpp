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
#define MAX 5010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str[MAX];
vector<int>mat[MAX];
int n,m,can[MAX];

void up(int p)
{
    int cnt[26]={0};
    FOR(i,0,m-1)
    {
        int a=str[p][i]-'a';
        if(cnt[a])can[p]++;
        cnt[a]++;
    }
    FOR(i,0,m-1)
        if(str[0][i]!=str[p][i])mat[p].PB(i);
}

int doit(int p)
{
    FOR(k,0,(int)mat[p].size()-1)
    {
        int x=mat[p][k];
        if(str[0][x]!=str[p][x]) return 0;
    }
    return 1;
}

int check(int f,int s)
{
   //// cout<<str[0]<<NL;
    FOR(p,1,n-1)
    {
        mat[p].PB(f); mat[p].PB(s);
        int a=0,b;
        FOR(i,0,(int)mat[p].size()-1)
        {
            FOR(j,i+1,(int)mat[p].size()-1)
            {
                int x=mat[p][i], y=mat[p][j];
                if(x==y)continue;

                swap(str[p][x],str[p][y]);
               //// cout<<p<<' '<<str[p]<<NL;
                a=max(a,doit(p));
                swap(str[p][x],str[p][y]);

                if(a)break;
            }
            if(a)break;
        }

        if(a==0&&can[p]==1)a=max(a,doit(p));
        mat[p].pop_back(); mat[p].pop_back();
       /// cout<<p<<' '<<a<<NL;
        if(a==0)return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j;

    cin>>n>>m;
    FOR(i,0,n-1)cin>>str[i];
    FOR(i,1,n-1)up(i);

    FOR(i,0,m-1)
    {
        FOR(j,i+1,m-1)
        {

            swap(str[0][i],str[0][j]);
            if(check(i,j))
            {
                cout<<str[0]<<NL;
                return 0;
            }
            ////cout<<str[0]<<' '<<check()<<NL<<NL;
            swap(str[0][i],str[0][j]);

        }
    }
    cout<<-1<<NL;

    return 0;
}


