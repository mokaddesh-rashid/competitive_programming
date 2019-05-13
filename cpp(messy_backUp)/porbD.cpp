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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int n, m, x, ara[MAX], y, p, chk;


int main()
{
   /// ios::sync_with_stdio(false);
   /// inf;
    //outf;

    cin >> m >> n;

    FOR(i,1,n)
    {
        cout << m << endl;
        cout << flush;

        cin >> ara[i];
        if(ara[i] == 0) return 0;
        if(ara[i] == -1) ara[i] = 1;
        else ara[i] = -1;
    }

    int st = 1, en = m, mid;

    p = 1;
    while(st <= en)
    {
        mid = (st + en)>>1;

        cout << mid << endl;
        cout << flush;

        cin >> chk; chk *= ara[p];

        if(chk == 0) return 0;
        else if(chk == -1) en = mid - 1;
        else st = mid + 1;

        if(p == n) p = 0;
        p++;
    }

    return 0;
}
