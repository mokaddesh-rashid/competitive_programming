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

int ar[100010], num[100010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i, j, x, y, n, m, st, en, mid, v, k, q, a, b, c;
        cin>>n>>k>>q;
        FOR(i,0,k-1) cin>>ar[i], num[i]=ar[i];
        sort(ar,ar+k);
        cout<<"Case "<<tt<<":"<<NL;
        FOR(i,0,q-1)
        {
            cin>>a;
            if(a<=k) cout<<num[a-1]<<NL;
            else
            {
                x=1000000001;
                a-=k;
                st=1; en=n;
                while(st<=en)
                {
                    mid=(st+en)/2;
                    v=upper_bound(ar,ar+k,mid)-ar;
                    //cout<<mid<<' '<<v<<' '<<ar[v]<<endl;
                    v=mid-v;
                    //cout<<mid<<' '<<v<<endl;
                    if(v>=a) en=mid-1, x=min(x,mid);
                    else st=mid+1;
                }
                cout<<x<<NL;
            }
        }
    }
    return 0;
}


