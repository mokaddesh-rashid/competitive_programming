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
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str;
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,c,mx=0;
    cin>>str;
    n=str.size();
    i=0;

    FOR(i,0,n-1)
    {
        a=0; b=0;
        while(i<n)
        {
            if(str[i]=='(') a++;
            else
            {
                a--;
                if(a==-1) break;
                b++;
            }
            i++;
        }
        cout<<i<<' '<<b<<NL;
        if(mx<b) mx=b,c=1;
        else if(mx==b) c++;
    }
    if(mx==0) c=1;
    cout<<mx*2<<' '<<c<<NL;
    return 0;
}
