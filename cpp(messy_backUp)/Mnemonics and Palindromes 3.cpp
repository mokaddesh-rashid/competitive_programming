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
#define MAX 100010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n,cnt;
vector<string> pp;

void rec(string str)
{
    //cout<<str<<NL;
    if(str.size()==n)
    {
        cout<<str<<NL;
        return;
    }
    int x=str.size();
    if(str.size()==0)
    {
        rec(str+"a");
        rec(str+"b");
        rec(str+"c");
    }
    else if(str[x-1]=='a'&&x==1)
    {
        rec(str+"b");
        rec(str+"c");
    }
    else if(str[x-1]=='b'&&x==1)
    {
        rec(str+"a");
        rec(str+"c");
    }
    else if(str[x-1]=='c'&&x==1)
    {
        rec(str+"a");
        rec(str+"b");
    }
    else if(str[x-1]=='c'&&str[x-2]=='b') rec(str+"a");
    else if(str[x-1]=='a'&&str[x-2]=='c') rec(str+"b");
    else if(str[x-1]=='a'&&str[x-2]=='b') rec(str+"c");

    else if(str[x-1]=='b'&&str[x-2]=='c') rec(str+"a");
    else if(str[x-1]=='c'&&str[x-2]=='a') rec(str+"b");
    else if(str[x-1]=='b'&&str[x-2]=='a') rec(str+"c");
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,a=0,b,c,x=100000;

    cin>>n;
    FOR(i,0,n-1)
    {
        if(i==0)c=3;
        else if(i==1) c=c*2;
        if(c>x) a=1;
    }
    c=c*n;
    if(c>x) a=1;

    cout<<c<<NL;
    if(a==1) cout<<"TOO LONG"<<NL;
    else rec("");
    return 0;
}


