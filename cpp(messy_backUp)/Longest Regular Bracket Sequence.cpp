#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for( i=j;i<=k;i++)
#define REV(i,j,k) for( i=j;i>=k;i--)
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
map<int,int>mp;
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,mx=0,c=1;
    cin>>str; n=str.size();

    FOR(i,0,n-1)
    {
        if(str[i]=='(')
        {
            a=0;
            FOR(j,i,n-1)
            {
                if(str[j]=='(') a++;
                else a--;
                if(a==-1) break;
                x=mp[a]; x--; y=mp[a+1];  y--;
                if(y>=i&&str[j]==')')
                {
                   b=j-y+1;
                   if(b>mx) cout<<j<<' '<<y<<' '<<a<<NL, mx=b, c=1;
                   else if(b==mx) c++;
                }
                if(x<i)
                {
                    cout<<a<<' '<<i+1<<NL;
                    mp[a]=j+1;
                }
            }
            i=j;

        }
    }
    if(mx==0) c=1;
    cout<<mx<<' '<<c<<NL;
    return 0;
}