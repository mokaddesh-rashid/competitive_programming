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

int cnt[32][MAX], n, m;
string str[MAX];
map<LL,int> mopa[32];

int getID(int lev,LL val)
{
    if( mopa[lev][val] == 0) mopa[lev][val] = mopa[lev].size();
    return mopa[lev][val];
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;

    cin >> n >> m;
    FOR(i,0,n-1)
    {
        cin >> str[i];
        FOR(j,1,(1<<m) - 1)
        {
            LL ba = 1, val = 0;
            FOR(k,0,m-1)
            {
                if(j & (1<<k))
                {
                    int x = str[i][k] - 'a'; x++;
                    val += (ba * x);
                }
                ba *= 31;
            }
            int id = getID(j, val);
            cnt[j][id]++;
        }
    }

    int x, show, q, p;

    cin >> q;
    FOR(t,1,q)
    {
        cin >> p;

        show = n;
        FOR(j,1,(1<<m) - 1)
        {
            LL ba = 1, val = 0, c = 0;
            FOR(k,0,m-1)
            {
                if(j & (1<<k))
                {
                    int x = str[p][k] - 'a'; x++;
                    val += (ba * x);
                    c++;
                }
                ba *= 31;
            }
            int id = getID(j, val);
            if(c%2) show -= cnt[j][id];
            else show += cnt[j][id];
        }
        cout << show << endl;
    }

    return 0;
}

