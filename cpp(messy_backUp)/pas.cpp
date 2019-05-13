#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define MEM(n, val) memset(n, val, sizeof(n))
#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define LL long long
#define F first
#define S second
#define PII pair<int, int>
#define PDD pair<double, double>
#define INF 1999999999
#define MP make_pair
#define LN (node * 2)
#define RN ((node * 2) + 1)
#define MX 100010
#define SF(a) scanf("%d", &a)
#define SFF(a, b) scanf("%d %d", &a, &b)
#define MOD 1000000007

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

class data  {
public:
    int mn, mx, vv;
    data()  {}
    data(int a, int b, int c)  {
        mn = a;
        mx = b;
        vv = c;
    }
};

int n;
data ara[100100];
int cost[100100];

int main()  {
    ///std::ios_base::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n)   {
        int mn, mx, vv;
        cin >> mn >> mx >> vv;
        ara[i] = data(mn, mx, vv);
    }
    int q;
    cin >> q;
    ///cout << q << "\n";
    FOR(i, 1, q)   {
        int cmd;
        int l, r;
        cin >> cmd >> l >> r;
        ///cout << cmd << " " << l << " " << r << "\n";
        if(cmd == 1)    {///update
            int tp, val;
            cin >> tp >> val;
            FOR(j, l, r)   {
                if(tp == 1)    {
                    ara[j].mn = val;
                }
                else if(tp == 2)   {
                    ara[j].mx = val;
                }
                else    {
                    ara[j].vv = val;
                }
            }
        }
        else    {///query
            int ans = -INF;
            FOR(j, l, r)   {
                ans = max(ans, ara[j].vv + ara[j].mx - ara[j].mn);
            }

            ///cout << l << " " << r << " : ";
            cout << ans << "\n";
        }
    }
    return 0;
}
/**
6
100 100 200
1 2 3
3 4 5
4 5 6
6 7 8
7 8 9
3
1 1 1 1 500
2 1 6
2 1 1
*/
