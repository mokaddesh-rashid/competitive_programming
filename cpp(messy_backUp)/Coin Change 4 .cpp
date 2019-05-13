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
#define LL           unsigned int
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

LL n, m, p, q, ar[1000], br[1000], F[1000100], S[1000100];
void rec(int x, int y)
{
    F[p] = y; p++;
    if(x==n)return;
    rec(x+1,y);
    rec(x+1,y+ar[x]);
    rec(x+1,y+ar[x]+ar[x]);
    return;
}
void rec2(int x, int y)
{
    S[q] = y; q++;
    if(x==m)return;
    rec2(x+1,y);
    rec2(x+1,y+br[x]);
    rec2(x+1,y+br[x]+br[x]);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    int tt;
    cin >> tt;
    FOR(t,1,tt)
    {
        //mem(F,0); mem(S,0);
        LL i, j, x, y, a, b, c = 0, k;
        p = q = 0;
        cin >> n >> k;

        x = n/2; y = n-x;
        n = x; m = y;
        FOR(i,0,n-1) cin>>ar[i];
        FOR(i,0,m-1) cin>>br[i];
        rec(0,0);
        rec2(0,0);

        //sort( F, F+p);
        sort( S, S+q);

        FOR(i,0,p-1)
        {
            //cout << F[i] << ' ';
            x = k-F[i];
            a = lower_bound(S,S+q,x)-S;
            if(F[i]+S[a]==k) c = 1;
        }
        if(c==1)cout <<"Case "<<t<<": Yes"<< endl;
        else cout <<"Case "<<t<<": No"<< endl;
    }
    return 0;
}


