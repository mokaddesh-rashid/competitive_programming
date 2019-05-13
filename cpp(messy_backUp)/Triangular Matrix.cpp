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
#define MAX 3010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str[MAX],ans;
vector<int>se,ef;
int n,ase[MAX];

void rec()
{
    char ch,ck,cf,cs;
    int x,y,z,a,b,c;

    FOR(i,0,n-1)
    {

        if(i==0) se.PB(0), ck=str[i][0];
        else
        {
            FOR(j,0,(int)se.size()-1)
            {
                x=se[j];
                if(j==0) ck=min(str[i][x],str[i][x+1]);
                else ck=min(ck,str[i][x+1]), ck=min(str[i][x],ck);
            }

            FOR(j,0,(int)se.size()-1)
            {
              x=se[j];

              if(str[i][x]==ck&&ase[x]==0)ef.PB(x),ase[x]=1;
              if(str[i][x+1]==ck&&ase[x+1]==0)ef.PB(x+1),ase[x+1]=1;
            }
            se.clear();

            FOR(j,0,(int)ef.size()-1)
            {
                x=ef[j];
                se.PB(x);
            }
            ef.clear(); mem(ase,0);
        }
        cout<<ck;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j;

    cin>>n;
    FOR(i,0,n-1)cin>>str[i];
    rec();
    return 0;
}


