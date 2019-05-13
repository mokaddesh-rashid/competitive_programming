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
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

struct info
{
    string nm, ct, ans;
    int p;
};
class Compare
{
public:
    bool operator()(info x,info y)
    {
       if(x.nm==y.nm) return x.ct<y.ct;
       else return x.nm<y.nm;
    }
};
class Compare2
{
public:
    bool operator()(info x,info y)
    {
       return x.p<y.p;
    }
};
string str,f,s;
info ar[1001];
set<string>ms;
set<string>::iterator it;
int ty[10010];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    string chk="AAA", ck="A";
    int i, j, x, y, n, m, a=0, b, c;
    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>f>>s; chk[0]=f[0]; chk[1]=f[1]; chk[2]=f[2];
        ck[0]=s[0];
        ar[i].nm=chk; ar[i].ct=ck; ar[i].p=i;
    }
    sort(ar,ar+n,Compare());
    FOR(i,0,n-1)
    {
        c=0;
        if(i<n-1&&ar[i].nm==ar[i+1].nm) c=1;
        if(i>0&&ar[i].nm==ar[i-1].nm) c=1;
        if(c==1)
        {
           ty[ar[i].p]=c;
           chk=ar[i].nm; chk[2]=ar[i].ct[0];
           it=ms.find(chk);
           if(it!=ms.end()) a=1;
           ms.insert(chk);
        }

    }
    FOR(i,0,n-1)
    {
        c=0;
        if(i<n-1&&ar[i].nm==ar[i+1].nm) c=1;
        if(i>0&&ar[i].nm==ar[i-1].nm) c=1;
        if(c==0)
        {
           chk=ar[i].nm; chk[2]=ar[i].ct[0];
           it=ms.find(chk);
           if(it==ms.end())
           {
               ty[ar[i].p]=1;
               ms.insert(chk);
           }
           else
           {
               chk=ar[i].nm;
               it=ms.find(chk);
               cout<<chk<<NL;
               if(it!=ms.end()) a=1;
               ty[ar[i].p]=0, ms.insert(chk);
           }
        }

    }
    if(a==1) cout<<"NO";
    else
    {
        cout<<"YES"<<NL;
        sort(ar,ar+n,Compare2());
        FOR(i,0,n-1)
        {
            chk=ar[i].nm;
            if(ty[i]==1) chk[2]=ar[i].ct[0];
            cout<<chk<<NL;
        }
    }
    return 0;
}


