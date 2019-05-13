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
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL hasho[4*MAX][MAX], len[4*MAX];
string str[4*MAX],in;

void up(string str,int p)
{
    len[p]=str.size();

    LL a=1,b,c=0;
    FOR(i,0,len[p]-1)
    {
        c+=(str[i]*a); ///c%=mod;
        a*=131; ///a%=mod;

        hasho[p][i]=c;
    }
}

int Compare(int x,int y,int m)
{
    int v=min(len[x],len[y]),st,en,mid,c=-1,d;

    st=0; en=min(v-1,m);
    while(st<=en)
    {
        mid=(st+en)/2;
        if(hasho[x][mid]==hasho[y][mid])st=mid+1,c=max(c,mid);
        else en=mid-1;
    }

    if(c==-1)return 1;
    else
    {
        d=c+1;
        c++;
        c*=2;
        c++;
        if(d==len[x]&&d==len[y])c++;
        return c;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    FOR(tt,1,100)
    {
        LL i,j,n,m,c=0;

        cin>>n;
        if(n==0)break;

        FOR(i,0,n-1)cin>>str[i];
        sort(str,str+n);

        FOR(i,0,n-1)up(str[i],i);

        FOR(i,0,n-1)
        {
            m=1000;
            FOR(j,i+1,n-1)
            {
               m=Compare(i,j,m);
               c+=m;
               m/=2;
               //if(m==0)break;
            }
        }

        cout<<"Case "<<tt<<": "<<c<<NL;
    }
    return 0;
}
