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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

multiset<int> sota;
PR ara[MAX];
LL val = 0;
int cnt[MAX], n, vld[MAX];
vector<int> mat[MAX];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    LL prin, c, mx = 0;

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i].S >> ara[i].F, val += ara[i].F;

    sort(ara, ara + n);
    reverse(ara, ara + n);

    prin = val; c = n;
    FOR(i,0,n-1)
    {
        int v = ara[i].F, p = ara[i].S;
        val -= v;
        c--;

        if(cnt[ p ]) sota.erase( sota.find( cnt[ p ] ) );
        cnt[p]++;
        sota.insert( cnt[p] );


        FOR(j,i,n-1)
        {
            int v = ara[j].F, p = ara[j].S;

            if(c > *(sota.rbegin())) break;
            if(vld[j]) continue;

            val += ara[j].F;
            c++;
            vld[j] = 1;

            if(cnt[ p ]) sota.erase( sota.find( cnt[ p ] ) );
            cnt[p]--;
            if(cnt[p]) sota.insert( cnt[p] );
        }

        prin = min(prin, val);

    }

    cout << val << endl;

    return 0;
}
