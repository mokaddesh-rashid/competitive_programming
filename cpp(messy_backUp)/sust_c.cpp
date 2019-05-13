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
#define mud          10000007
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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str[MAX];
int n, m;

pr hash_v(string bit)
{
    LL a,b=0,c=0,x=1,y=1, d=0;
    FOR(i,0,m-1)
    {
       b=a=bit[i]-'a';

       a=a*x;   b=b*x;
       c+=a;    d+=b;
       x*=29;   y*=29;
       c%=mod;  d%=mud;
       x%=mod;  y%=mud;
    }

    return MP(c,d);
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    map<pr,int> mapu;
    pr bo;
    int i,j;
    LL c=0;

    cin>>n>>m;
    FOR(i,0,n-1) cin>>str[i];
    FOR(i,0,n-1)
    {
        bo=hash_v(str[i]);
        mapu[bo]++;
    }

    FOR(i,0,n-1)
    {
        string chk=str[i];
        FOR(j,0,m-1)
        {
           FOR(k,0,25)
           {
              char ch='a'+k;
              if(str[i][j]==ch) continue;
              chk[j]=ch;
              bo=hash_v(chk);
              c+=mapu[bo];
              chk[j]=str[i][j];
           }
        }
    }

    cout<<c/2<<NL;
    return 0;
}


