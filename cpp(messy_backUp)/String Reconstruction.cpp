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
#define sz 1000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

set<int>ms;
set<int>::iterator it;
string str;
char prn[sz];
int ase[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,x,y,z=0;
    cin>>n;

    FOR(i,1,sz-1) prn[i]='a', ms.insert(i);

    FOR(i,0,n-1)
    {
        cin>>str;
        cin>>m;

        x=str.size();
        FOR(j,0,m-1)
        {
            cin>>a;
            b=a;
            z=max(z,a+x-1);
            while(true)
            {
                c=b-a;
                if(c>=x||b>z) break;
                else
                {
                    prn[b]=str[c];
                    if(ase[b]==0)
                    {
                        ms.erase(ms.find(b));
                        ase[b]=1;
                    }
                }
                it=ms.lower_bound(b+1);
                if(it!=ms.end()) b=*it;
            }
        }
    }

    FOR(i,1,z) cout<<prn[i];
    return 0;
}


