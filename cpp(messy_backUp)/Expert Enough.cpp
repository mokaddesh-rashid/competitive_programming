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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
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
#define sz 1000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[sz];
vector<int> st[sz], en[sz];
struct node
{
    string name;
    int s, e;
}in[10010];
set<int>ms;
set<int>::iterator it;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(ar,-1); clean(st,sz-1); clean(en,sz-1);
        int i,j,n,m,z,q,a,b,c=0,x,y;

        cin>>n;
        FOR(i,0,n-1)
        {
            cin>>in[i].name;
            cin>>in[i].s>>in[i].e;
            st[in[i].s].PB(i);
            en[in[i].e+1].PB(i);
        }
        FOR(p,0,sz-5)
        {
            FOR(j,0,(int)st[p].size()-1)
            {
                x=st[p][j];
                ms.insert(x);
                c++;
                ///cout<<p<<' '<<x<<NL;
            }
            FOR(j,0,(int)en[p].size()-1)
            {
                x=en[p][j];
                ms.erase(x);
                c--;
                ///cout<<p<<' '<<x<<NL;
            }

            if(c==1)
            {
               it=ms.begin();
               ar[p]=*it;
               ///cout<<p<<NL;
            }
        }

        cin>>q;
        FOR(i,0,q-1)
        {
            cin>>a;
            a=ar[a];
            if(a==-1) cout<<"UNDETERMINED"<<NL;
            else cout<<in[a].name<<NL;
        }
    }
    return 0;
}


