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

set<string>::iterator ii;
set<string>ms;
string str, chk;
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, p, e, c=0;
    cin >> n >> m ;
    FOR(i,0,n-1)
    {
        cin>>str;
        ms.insert(str);
    }
    FOR(i,0,m-1)
    {
        //cout<<c<<endl;
        cin>>str;
        ii=ms.find(str);
        if(ii!=ms.end())chk=*ii;
        if(chk==str) c++;
    }
    n-=c;
    m-=c;
    if(c%2)n++;
    if(n>m) cout<<"YES";
    else cout<<"NO";
    return 0;
}


