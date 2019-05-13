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
#define Mo          1000000000
#define M1          1000000007
#define M2          100000007
#define B1          29
#define B2          31
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 300010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

pr ar[MAX], inv[MAX], po[MAX], br[MAX];
string str,ss;

void info()
{
    LL n=str.size(),x=1,y=1;

    FOR(i,0,MAX-1)
    {
        po[i].F=x; x*=B1; x%=M1;
        po[i].S=y; y*=B2; y%=M2;
    }
}

LL hasho(string str)
{
    LL n=str.size(),m,i,j,a,b,c,x=0,y=0,z;

    FOR(i,0,n-1)
    {
       a=str[i]-'a';a++;
       x+=(po[i].F*a); y+=(po[i].S*a);
       x%=M1; y%=M2;
    }
    return x*Mo+y;
}

set<LL>mosa;
set<LL>::iterator it;


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    info();

    int i,j,n,m,c,p,d;
    LL a,b,x,y,z,l,o;

    cin>>n>>m;
    FOR(i,0,n-1)
    {
        cin>>str;
        mosa.insert(hasho(str));
    }

    FOR(i,0,m-1)
    {
        cin>>str;
        a=hasho(str);
        c=str.size(); d=0;

        FOR(j,0,c-1)
        {
            l=(a/Mo)+M1; o=(a%Mo)+M2;
            FOR(k,1,3)
            {
                p=str[j]-'a';p++;
                x=l; y=o;///Mo must be bigger than M1&M2
                x+=(po[j].F*((k-p)); y+=(po[j].S*(k-p));///check
                x%=M1; y%=M2;
                x=x*Mo+y;

                if(x!=a)
                {
                    it=mosa.find(x);
                    if(it!=mosa.end())
                    {
                        d=1;
                        break;
                    }
                }
            }
            if(d==1)break;
        }

        if(d==1)cout<<"YES"<<NL;
        else cout<<"NO"<<NL;
    }
    return 0;
}



