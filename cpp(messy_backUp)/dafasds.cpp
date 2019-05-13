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

vector<LL>mv;
void rec(LL n)
{
    if(mv.size()>100010) return;
    if(n==0||n==1)
    {
        mv.PB(n);
        return;
    }
    rec(n/2);
    rec(n%2);
    rec(n/2);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    FOR(tt,1,100)
    {
        LL i, j, x, y, n, m, l, r, c=0;
        n=tt;//cin>>n;
        rec(n);
        //cin>>l>>r;
//        FOR(i,l,r)
//        {
//            if(mv[i]==1) c++;
//        }
        cout<<mv.size()<<endl;
          mv.clear();
    }
    return 0;
}


