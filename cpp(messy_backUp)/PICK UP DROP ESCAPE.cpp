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

pr lola[2000010];
int ar[110], p, bs[2000010];

int cre()
{
    int z=1<<20;
    p=0;
    //cout<<z<<endl;
    FOR(i,1,z-1)
    {
        int bt=0;
        FOR(j,0,20)
            if(i&(1<<j))bt++;

        lola[p].F = bt;
        lola[p].S = i;
        p++;
        //if(i>990000)cout << i << ' ' << p << endl;
    }
    //cout<<p<<endl;
    sort(lola,lola+p);
    FOR(i,0,p) bs[i]=lola[i].F;
}
int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    cre();
    //cout << p << endl;
    int tt;
    //cin>>tt;
    sf(tt);
    FOR(t,1,tt)
    {
        int i, j, x, y, n, m, ole, prn=0, a, b, c;
        //cin >> n >> m ;
        sff(n,m);
        FOR(i,0,n-1) sf(ar[i]);//cin>>ar[i];
        x = lower_bound(bs,bs+p,m)-bs;
        while(lola[x].F==m)
        {
           a = lola[x].S;
           b = 0;
           ole = 0;
           FOR(j,0,20)
           {
               if(a&(1<<j))
               {
                   ole = ole^ar[j];
                   if(j>=n)
                   {
                       b=1;
                       break;
                   }
               }
           }
           //cout << ole << endl;
           if(b==0)prn=max(ole,prn);
           x++;
        }
        pf("%d\n",prn);
        //cout<<prn<<endl;
    }
    return 0;
}


