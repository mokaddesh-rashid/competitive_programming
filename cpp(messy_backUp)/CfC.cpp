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
#define MAX 1010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<LL> prin;
LL ar[MAX];
LL n, d, go;

int rec(int p,int v)
{
    ///cout << p << ' ' << v << endl;
    if(v == 0) return 1;
    if(p == 0 || prin.size() > 10000) return 0;

    if(v < ar[p]) return rec(p - 1, v);
    else
    {
        FOR(i,1,p)
        {
            prin.PB( go );
        }
        go += d;
        go++;

        return rec(p, v - ar[p]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int c = 2, co = 0;
    go = 1;

    cin >> n >> d;

    FOR(i,1,31)
    {
        ar[i] = c - 1;
        c *= 2;
        ///cout << i << ' ' << ar[i] << endl;
    }

    if(rec(31, n))
    {
        cout << prin.size() << endl;
        FOR(i,0,(int)prin.size()-1) cout << prin[i] << ' ';

//        int k = prin.size();
//
//        FOR(i,1,(1<<k)-1)
//        {
//            LL b = maxx, a = maxx * -1;
//            FOR(j,0,k-1)
//            {
//                if(i & (1<<j))
//                {
//                    a = max(a, prin[j]);
//                    b = min(b, prin[j]);
//                }
//            }
//            if(a - b <= d) co++;
//        }
//
//        cout << endl << co << endl;
    }
    else cout << "No" << endl;

    return 0;
}


