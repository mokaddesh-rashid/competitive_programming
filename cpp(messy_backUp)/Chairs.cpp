#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;


string str;
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,0,tc-1)
    {
        int i, j, x, y, n, m=0;
        cin>>n;
        cin>>str;
        FOR(i,0,n-1) if(str[i]=='1') m++;
        x=0; y=0;
        REV(i,n-1,0)
        {
            if(str[i]=='1') x++;
            else break;
        }
        FOR(i,0,n-1)
        {
            if(str[i]=='1') x++;
            else x=0;
            y=max(x,y);
        }
        cout<<max(0,m-y)<<NL;
    }
    return 0;
}

