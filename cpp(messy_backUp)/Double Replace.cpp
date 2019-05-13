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

string S,A,B;
int m,n;

int chk(int p,int v)
{
    string ok, ck;
    if(v==0) ok=A, ck=B;
    else ok=B, ck=A;

    int c=0;
    FOR(i,0,m-1)
    {
        if(p+i==n) break;
        else if(S[p+i]==ok[i]) c++;
    }

    if(c==m)
    FOR(i,0,m-1)
        S[p+i]=ck[i];

    if(c==m) return 1;
    else return 0;

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,a,b,c;

    cin>>S>>A>>B;
    n=S.size(); m=A.size();

    a=b=-1;
    FOR(i,0,n-1)
    {
        if(chk(i,0)) i=i+(m-1);
        else if(chk(i,1)) i=i+(m-1);
    }

    cout<<S<<NL;
    return 0;
}


