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

vector<int> old, notun;
int n, cnt[MAX];


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int v;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> v;
        old.PB( v );
    }

    int chao = 1, prin = 0;
    while(chao)
    {
        chao = 0;
        for(auto x : old)
        {
            if(notun.empty() || *(notun.rbegin()) != x)
                notun.PB( x );
        }
        int n = notun.size();
        FOR(i,1,n-2)
        {
            if(notun[i - 1] == notun[i + 1])
                notun[i] = notun[i + 1], chao = 1, prin++;
        }
        old.clear();
        for(auto x : notun) old.PB( x );
        notun.clear();
    }

    int cc = 0;
    for(auto x : old)
    {
        cnt[x]++;
        cc = max(cc, cnt[x]);
    }
    cout << prin + (old.size() - cc) << endl;


    return 0;
}

