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
#define MK make_pair
#define MAX 1000010
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str;
int cnt[MAX], stk[MAX], top;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    top=-1;
    int i,j,c,mx,a,n;
    cin>>str;
    n=str.size();

    i=0;
    while(i<n)
    {
        if(str[i]=='(')stk[++top]=i;
        else
        {
            ///cout<<top<<' '<<stk[top]<<' '<<' '<<i<<NL;
            if(top>=0)cnt[stk[top--]]=cnt[i]=1;
            else top=-1;
        }
        i++;
    }

    mx=a=0; c=1;
    FOR(i,0,n-1)
    {
        ///cout<<a<<NL;
        if(cnt[i]==1)a++;
        else a=0;

        ///cout<<cnt[i]<<' '<<a<<NL;
        if(a>mx)mx=a,c=0;
        if(a==mx&&mx>0)c++;
    }

    cout<<mx<<' '<<c<<NL;
    return 0;
}
