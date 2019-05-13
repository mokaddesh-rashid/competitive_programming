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

string str,ss;
int ar[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,c=1;
    char ch='A';

    cin>>str; n=str.size();
    cin>>ss; m=ss.size();

    i=0;j=0;
    while(j<m&&i<n)
    {
        if(str[i]==ss[j])i++,j++,ar[j]=1;
        else j++;
    }
    cout<<i<<NL;
    if(i==n)
    {
        FOR(i,0,m-1)
        {
            if(ar[i]==1) ch=ss[i];
            cout<<ch<<' '<<ss[i]<<NL;
            if(ch!=ss[i])c=0;
        }
    }
    else c=0;

    cout<<c<<NL;
    return 0;
}


