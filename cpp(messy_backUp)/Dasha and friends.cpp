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

int ar[1000], br[1000], fi[100], si[1000];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x=20, y, n, m, c=0, d=0, a=0, b;
    cin>>n>>m;
    FOR(i,0,n-1) cin>>ar[i];
    FOR(i,0,n-1) cin>>br[i];
    while(x--)
    {
        c=0;
        mem(fi,0);
        FOR(i,0,n-1)
        FOR(j,0,n-1)
        {
            if(ar[i]==br[j]&&fi[j]==0) {
                    fi[j]=1,c++;
                    break;
            }
        }
        if(c==n) d=1;
        FOR(i,0,n-1)
        {
            ar[i]--;
            if(ar[i]==-1)ar[i]=m-1;
            //cout<<ar[i]<<' ';
        }
        //cout<<endl;

    }
    //cout<<a<<' '<<d<<endl;
    if(d==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
