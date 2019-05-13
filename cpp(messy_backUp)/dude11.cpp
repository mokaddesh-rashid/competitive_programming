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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


//set<int>::iterator ii;

pr in[sz];
int pa[100001], mp[100001];

int fi_pa( int x )
{

    if( pa[x] == x )
        return x;
    else
       {
          pa[x] = fi_pa( pa[x] );
          return pa[x];
       }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int tc=10;
    cout<<tc<<NL;
    FOR(tt,1,tc)
    {
        int i, j, x, y, n, m, a, b;
        n=rand()%10; n++;
        a=(n*(n-1)/2);
        m=rand()%a;
        m++;
        cout<<n<<' '<<m<<NL;

        for(i=1;i<=n;i++)pa[i] = i;

        int p=0;
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                if(i==j) continue;
                in[p].F=i; in[p].S=j;
                p++;
            }
        }

        int d=10, c;
        while(d--)
        {
            ///if(m<=0) break;
            c=rand()%p;
            cout<<c<<' '<<p<<' '<<n<<' '<<a<<' '<<m<<' '<<d<<NL;
//            //FOR(i,c,min(c+5,p-1))
//            {
//                if(m<=0) break;
//                a=c;
//                b=in[a].S;
//                a=in[a].F;
//                x = fi_pa(a);
//                y = fi_pa(b);
//
//                if(x==y);//cout<<a<<' '<<b<<"con"<<NL;
//                else
//                {
//                    cout<<a<<' '<<b<<NL;
//                    mp[b] = a;
//                    pa[y] = x;
//                    m--;
//                }
//            }
        }
        cout<<NL;
    }
    return 0;

}

