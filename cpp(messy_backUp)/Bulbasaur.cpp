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

int cnt[100];///B u l b a s a u r
string str;
int i, j, x, y, n, m, B, u, l, b, a, s, r;
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    cin >>str;
    n=str.size();
    FOR(i,0,n-1)
    {
        if(str[i]=='B') B++;
        if(str[i]=='u') u++;
        if(str[i]=='l') l++;
        if(str[i]=='b') b++;
        if(str[i]=='a') a++;
        if(str[i]=='s') s++;
        if(str[i]=='r') r++;
    }
    x=B;
    x=min(x,u/2);
    x=min(x,l);
    x=min(x,b);
    x=min(x,a/2);
    x=min(x,s);
    x=min(x,r);
    cout<<x<<endl;
    return 0;
}


