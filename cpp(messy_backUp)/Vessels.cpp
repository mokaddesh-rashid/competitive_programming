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
#define sz 200010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

set<int>ms;
set<int>::iterator it;
int cur[sz], ful[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,q,a,b,c,t,x,y,z,v;

    sf(n);///cin>>n;
    FOR(i,1,n)
    {
        sf(ful[i]);///cin>>ful[i];
        ms.insert(i);
    }

    sf(q);///cin>>q;
    FOR(i,1,q)
    {
        sf(t);//cin>>t;
        if(t==1)
        {
            sff(x,v);///cin>>x>>v;
            while(true)
            {
                ///cout<<x<<' '<<v<<NL;
                a=cur[x]; b=ful[x];
                if(a+v<=b)
                {
                    cur[x]+=v;
                    if(cur[x]==ful[x]) ms.erase(ms.find(x));
                    break;
                }
                else if(cur[x]<ful[x])
                {
                    c=b-a;
                    ///cout<<b<<"   "<<a<<NL;
                    cur[x]=ful[x];
                    if(cur[x]==ful[x]) ms.erase(ms.find(x));
                    v=v-c;
                }

                it=ms.lower_bound(x+1);
                if(it==ms.end()) break;
                else x=*it;
            }
        }
        else
        {
            sf(x);
            pf("%d\n",cur[x]);
            ///cin>>x;
            ///cout<<cur[x]<<NL;
        }
    }

    return 0;
}


