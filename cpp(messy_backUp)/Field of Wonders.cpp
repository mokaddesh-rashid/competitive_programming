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
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str,chk;
int cnt[30],ase[30];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,x,y,z,c=0;

    cin>>n;
    cin>>str;

    cin>>m;
    FOR(i,0,m-1)
    {
        cin>>chk;
        mem(cnt,0);
        FOR(j,0,n-1)
        {
            x=chk[j]-'a';
            cnt[x]=1;
        }
        FOR(j,0,30)ase[j]=max(cnt[j],ase[j]);
    }

    mem(cnt,0);
    FOR(j,0,n-1)
    {
        x=str[j]-'a';
        if(x>=0&&x<28) cnt[x]=1;
    }
    c=0;
    FOR(i,0,30)
    {
        //cout<<cnt[i]<<' '<<ase[i]<<NL;
        if(cnt[i]==0&&ase[i]==m)c++;
    }
    cout<<c<<NL;

    return 0;
}


