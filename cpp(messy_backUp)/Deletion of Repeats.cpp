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
typedef pair<int,int> pr;

struct node
{
    int l,r,p;
};

class compare
{
    public:
    bool operator()(node f, node s)
    {
        if(f.l == s.l) return f.r < s.r;
        else return f.l < s.l;
    }
};

node ar[MAX];
int sfx[20][MAX], ole[MAX], n;
int str[MAX];

void up()
{
    int x = 1, m;

    FOR(i,0,n-1) sfx[0][i] = str[i];

    FOR(j,1,19)
    {
        FOR(i,0,n-1)
        {
           ar[i].l = sfx[j-1][i];
           ar[i].r = -1;
           if(i + x < n) ar[i].r = sfx[j-1][i+x];
           ar[i].p = i;
        }
        sort(ar, ar + n, compare());
        m = 0;
        FOR(i,0,n-1)
        {
            if(i>0)
            {
                if(!(ar[i].l == ar[i-1].l && ar[i].r == ar[i-1].r)) m++;
            }
            sfx[j][ar[i].p] = m;
        }
        x *= 2;
    }

    FOR(j,0,n-1)
    {
        ole[ar[j].p] = j;
       // cout << ar[j].p << ' ' << j << endl;
    }

}

int lcp(int f,int s,int t)
{
    int x = 1<<t;

    if(t == -1) return 0;
    else if(max(f + x,s + x) <= n && sfx[t][f] == sfx[t][s]) return (1<<t) + lcp(f + (1<<t), s + (1<<t), t);
    else return lcp(f, s, t - 1);
}


int cnt[MAX];
set<pr> sota;

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    int prin = 0;
    cin >> n;
    FOR(i,0,n-1) cin >> str[i];
    up();

    int x = 1;
    FOR(i,0,n-1)
    {
        int p = ole[i];
        FOR(j,max(0,p - 10),min(n - 1, p + 10))
        {
            int lo = ar[j].p;

            if(lo > i && i + lcp(i, lo, 19) >= lo)
            {
                ///prin = max(prin, lo);
                sota.insert(MP(lo - i, lo));
            }
        }
    }

    while(!sota.empty())
    {
        pr use = *(sota.begin());
        ///cout << use.F << ' ' << use.S << endl;

        if((use.S - use.F) + 1 > prin)
        {
            prin = use.S;
        }

        sota.erase( sota.begin() );
    }

    cout << n - prin << endl;
    FOR(i,prin,n-1) cout << str[i] << ' ';

    return 0;
}



