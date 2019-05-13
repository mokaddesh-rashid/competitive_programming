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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;


class Compare
{
public:
    bool operator()(pr x, pr y)
    {
        if(x.S==y.S)return x.F>y.F;
        else return x.S>y.S;
    }
};
set<pr,Compare>ms;
set<pr>::iterator it;
map<int,int>mp;
map<int,int>::iterator ii;
struct info
{
    int a,b,c;
}ar[100010];

void print(int a,int b,int c)
{
    int pr[]={a,b,c};
    sort(pr,pr+3,greater<int>());
    FOR(i,0,2) cout<<pr[i]<<' ';
    cout<<NL;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,c=0;
    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>a;
        mp[a]++;
    }
    for(ii=mp.begin();ii!=mp.end();ii++)
    {
        a=ii->F; b=ii->S;
        ms.insert(MK(a,b));
        //cout<<a<<' '<<b<<NL;
    }
    //cout<<ms.size()<<NL;
    while(ms.size()>=3)
    {
        pr l,m,s;
        it=ms.begin(); l=*it; ms.erase(ms.begin());
        it=ms.begin(); m=*it; ms.erase(ms.begin());
        it=ms.begin(); s=*it; ms.erase(ms.begin());
        ar[c].a=l.F; ar[c].b=m.F; ar[c].c=s.F;
        c++;
        l.S--; m.S--; s.S--;
        if(l.S>0) ms.insert(l);
        if(m.S>0) ms.insert(m);
        if(s.S>0) ms.insert(s);
    }
    cout<<c<<NL;
    FOR(i,0,c-1)
    {
        print(ar[i].a,ar[i].b,ar[i].c);
    }
    return 0;
}


