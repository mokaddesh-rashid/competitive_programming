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

int ar[MAX];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m;
    LL c=0,x=0,a;

    cin>>n;
    FOR(i,0,n-1)cin>>ar[i];

    while(n>2&&ar[n-1]<ar[n-2])
    {
        n--;
    }

    x=0;
    FOR(i,0,n-1)
    {
        if(i==0)x=ar[i];
        else if(i!=n-1)
        {
            if(x>=ar[i]) c+=((x-ar[i])+1),x++;
            else x=ar[i];
        }
        else if(x==ar[n-1])
        {
            a=1;
            while(n-i>1)
            {
               c+=a;
               a++;
               i++;
               n--;
            }
            c+=a;
        }
        else
        {
            if(x==ar[i])c++;
        }
    }
    cout<<c<<NL;
    return 0;
}


