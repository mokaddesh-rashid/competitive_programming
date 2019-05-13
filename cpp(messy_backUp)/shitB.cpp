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
#define MAX 210
#define MP make_pair
#define valid(nx,ny)  ((nx >= 1) && (nx < row) && (ny >= 1) && (ny < col))
typedef pair<int,int> pr;

string str[110];
int n, k, row, col, cnt[MAX][MAX];

int rec(int px,int py,int fo,int so,int v)
{
    if(v == 0) return 1;
    if(!valid(px, py)) return 0;
    if(str[px][py] == '#') return 0;

    int temp = rec(px + fo, py + so, fo, so, v - 1);
    cnt[px][py] += temp;
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
   inf;
    //outf;

    cin >> n >> k;

    FOR(i,1,n) cin >> str[i], str[i] = "#" + str[i];
    row = n + 1, col = n + 1;

    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            rec(i, j, 1, 0, k);
            rec(i, j, 0, 1, k);
        }
    }

    //rec(1, 2, 1, 0, k);
    ///rec(1, 2, 0, 1, k);
    int px, py;

    px = py = 1;
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            cout << cnt[i][j] << ' ';
            if(cnt[px][py] < cnt[i][j])
            {
                px = i;
                py = j;
            }
        }
        cout << endl;
    }

    cout << px << ' ' << py << endl;

    return 0;
}

