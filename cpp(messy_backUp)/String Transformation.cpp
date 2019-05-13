#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000007
#define mod2          100000007
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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str, cmp;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,x,y,z,v,k,d=0;

    getline(cin,str);
    n=str.size();
    ///cout<<n<<NL;
    getline(cin,cmp);
    m=cmp.size();

    if(n!=m)
    {
        cout<<-1<<' '<<-1<<NL;
        return 0;
    }

    y=m-1;
    FOR(x,0,n-2)
    {
       if(str[x]!=cmp[y]) break;
       y--;
       a=x; v=y;
    }

    z=0;
    FOR(x,x,n-1)
    {
        b=x;
        if(str[x]!=cmp[z]) break;
        z++;
    }

    k=n-1;
    FOR(i,z,v)
    {
        if(cmp[i]!=str[k]) d=1;
        k--;
    }

    if(d==1) cout<<-1<<' '<<-1<<NL;
    else cout<<a<<' '<<b<<NL;
    return 0;
}


