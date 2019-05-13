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
#define MAX 1000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL ar[MAX],sm[MAX],ase[MAX];


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,n,m,a,b,c,d,e,f,g=0;

    cin>>n>>m;
    FOR(i,0,n-1)cin>>ar[i],g+=ar[i];

    a=0;b=0;c=ar[0];
    i=j=0;j++;

    while(i<n)
    {
        c=ar[i]+sm[i];
        j=i+1;
        ///cout<<i<<' '<<j<<' '<<c<<' '<<g<<NL;
        while(j<n)
        {
            if(g-c<=m)
            {
                ///cout<<i<<NL;
                g=ar[i];
                ase[i]=1;
                break;
            }

            if(ar[j]-c>m)
            {
                sm[j]=c;
                i=j-1;
                break;
            }
            else c+=ar[j];

            j++;
            if(g-c<=m)
            {
                ///cout<<i<<NL;
                g=ar[i];
                ase[i]=1;
                break;
            }
        }

        if(g-c<=m&&ase[i]==0)
        {
            g=ar[i];
            ase[i]=1;
        }
        i++;
    }

    FOR(i,0,n-1) if(ase[i]==1)cout<<i+1<<' ';
    return 0;
}


