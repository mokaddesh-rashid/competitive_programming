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
typedef pair<LL,LL> pr;

double opa;

LL calculate(double up,double dn)
{
    LL x = up, y = dn, ret;
    double val = (up / dn) * 100, cmp;
    ret = val;
    cmp = ret;
    cmp += .5;

    if(cmp < val) ret++;

    return ret;
}

LL oka(double up,double dn)
{
    LL x = up, y = dn, ret;
    double val = (up / dn) * 100, cmp;
    ret = val;
    cmp = ret;
    cmp += .5;
    //cout << cmp << ' ' << val << endl;
    if(cmp < val) return 1;

    return 0;
}

LL ar[MAX], shit[MAX], po;
pr cls[MAX];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    LL tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        po = 0;
        LL prin = 0, ret = 0;
        LL n, m, cnt, x, up;

        cin >> n >> m;

        up = 1; po = 0; mem(shit, 0);
        FOR(i,1,n)
        {
            ///cout << calculate(i, n) << ' ' << oka(i, n) << endl;
            if(oka(i, n))
            {
                ///cout << i << endl;
                shit[po] = i;
                po++;
            }
        }

        mem(ar, 0);
        cnt = n;
        FOR(i,0,m-1)
        {
            cin >> ar[i];
            cnt -= ar[i];
        }

        FOR(i,0,n-1)
        {
            x = lower_bound(shit, shit + po, ar[i]) - shit;
            if(x == po)
            {
                cls[i].F = -1;
                cls[i].S = i;
            }
            else
            {
                cls[i].F = shit[x] - ar[i];
                cls[i].S = i;
            }
        }

        sort(cls, cls + n);
//        FOR(i,0,n-1) cout << cls[i].F << ' ' << cls[i].S << endl;
//        cout << cnt << endl;
        FOR(i,0,n-1)
        {
            if(cnt && cls[i].F != -1)
            {
                if(cls[i].F > cnt)
                {
                    ar[ cls[i].S ] += cnt;
                    cnt = 0;
                }
                else
                {
                    ar[ cls[i].S ] += cls[i].F;
                    cnt -= cls[i].F;
                }
            }
            else if(i == n - 1) ar[ cls[i].S ] += cnt, cnt = 0;
            ///cout << ar[ cls[i].S ] << ' ' << cnt << endl;
            ///cout << calculate(ar[ cls[i].S ], n) << endl;
            prin += calculate(ar[ cls[i].S ], n);

        }

        ///prin += calculate(1, n) * cnt;


        cout << "Case #" << tt << ": " << prin << endl;
    }
    return 0;
}
