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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[sz];
multiset<int>ms;
multiset<int>::iterator it;
map<int,int> mp;

void soln(int x)
{
    int a,b,c=-1,st,en,mid;
    st=1; en=x;

    while(st<=en)
    {
        mid=(st+en)>>1;
        it=ms.lower_bound(mid);

        if(it==ms.end()) en=mid-1;
        else if(*it>=x) en=mid-1;
        else
        {
            st=*it+1;
            c=*it;
        }
    }

    if(c==-1)
    {
        it=ms.lower_bound(x);
        c=*it;
    }
    it=ms.find(c);
    ms.erase(it);
    cout<<c<<' ';

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];

    FOR(i,0,n-1)
    {
        if(i==0) ms.insert(ar[i]), ms.insert(ar[i]);
        else
        {
            soln(ar[i]);
            ms.insert(ar[i]); ms.insert(ar[i]);
        }
    }
    return 0;
}

