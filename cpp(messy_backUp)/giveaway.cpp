
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
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;


int prin;
string str;

string getString(int v)
{
    string ret = "";

    while(v)
    {
        int p = v%10;
        char ch = p + '0';
        ret = ch + ret;
        v /= 10;
    }

    return ret;
}

bool isPalin(int p)
{
    string val = getString( p );
    int n = val.size();
    int i = 0, j = n - 1;

    while(i < j)
    {
        if(val[i] != val[j]) return 0;
        i++; j--;
    }

    return 1;
}

int pal[MAX], p;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    FOR(i,100000,999999)
        if(isPalin( i )) pal[p++] = i;

    int n, val, prin, show, pos, x, y;

    cin >> n;

    FOR(i,0,n-1)
    {
        cin >> val;
        x = lower_bound(pal, pal + p, val) - pal;
        x -= 2; x = max(0, x);
        y = min(p - 1, x + 2);

        FOR(i,x,y)
        {
            ///cout << pal[i] << ' ';
            if(i == x)
            {
                prin = abs(pal[i] - val);
                show = pal[i];
            }
            else if(prin > abs(pal[i] - val))
            {
                prin = abs(pal[i] - val);
                show = pal[i];
            }
        }

        cout << show << endl;
    }

    return 0;
}
