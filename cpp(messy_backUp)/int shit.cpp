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
#define SZ 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


int mo, v, vis[MAX], ty[MAX], pa[MAX], stk[MAX];

void bfs(int p)
{
   int h=0, r=0;
   stk[r]=p; r++; vis[p]=1; pa[p]=-1, ty[p]=p;

   while(h!=r)
   {
       p=stk[h]; h++;
       vis[p]=1;

       int a=(p*10)%mo;
       if(vis[a]==0)
       {
           pa[a]=p;
           vis[a]=1;
           ty[a]=0;
           stk[r]=a;
           r++;
       }

       a=((p*10)+v)%mo;
       if(vis[a]==0)
       {
           pa[a]=p;
           vis[a]=1;
           ty[a]=v;
           stk[r]=a;
           r++;
       }
   }

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin>>mo>>v;
    bfs(v);
    if(mo==v)
    {
        cout<<v;
        return 0;
    }
    string str="";

    int a=0;
    while(true)
    {
        char ch=ty[a]+'0';
        str=ch+str;

        if(pa[a]==-1)break;
        a=pa[a];
    }
    cout<<str<<NL;
    return 0;
}


