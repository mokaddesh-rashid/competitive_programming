#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
typedef pair<LL,LL> pr;

LL n, k, p, m;
LL rec(LL x, LL y, LL t)
{
    //cout<<x<<' '<<y<<' '<<t<<endl;
    if(k-2==t&&x==p) {
        return 1;
    }
    if(t==k-2) return 0;
    else return rec(x+y,x,t+1);
}

int solve(int j, int i)
{
    int a=rec(j,i,0), b;
    if(a==1)
    {
            b=0;
            FOR(k,0,i-1) cout<<"AC", b+=2;
            while(b<n)
            {
                cout<<'D';
                b++;
            }
            cout<<endl;
            b=0;
            FOR(k,0,j-1) cout<<"AC", b+=2;
            while(b<m)
            {
                cout<<'D';
                b++;
            }
            cout<<endl;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i, j, x, y, a, b;
    cin>>k>>p>>n>>m;
    x=n/2;
    y=m/2;
    FOR(i,0,x)
    FOR(j,0,y)
    {
        a=solve(j,i);
        if(a==1) {return 0;}
        //cout<<i<<'k'<<j<<endl;
    }
    k--;
    a=rec(1,0,0);
    if(a==1)
    {
       FOR(i,0,n-2) cout<<'D';
       cout<<"A\nC"<<endl;
       FOR(i,0,m-2) cout<<'D';
       return 0;
    }
    cout<<"Happy new year!";
    return 0;
}


