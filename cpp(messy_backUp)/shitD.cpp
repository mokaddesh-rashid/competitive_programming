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
typedef pair<int,int> pr;

vector<int> mat[MAX];
int  in[MAX], n, ase[MAX];
set<int> sota;

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;
    int p;
    vector<int> prin;

    cin >> n;
    FOR(i,1,n)
    {
        cin >> p;

        if(p)
        {
            in[i]++;
            in[p]++;
            mat[i].PB(p);
            mat[p].PB(i);
        }
    }

    FOR(i,1,n)
    {
        if(in[i]%2 == 0)
        {
            sota.insert( i );
            ///;cout << i << endl;
        }
    }

    while(!sota.empty())
    {
        p = *(sota.begin()); sota.erase( sota.begin() );
        ase[p] = 1;
        prin.PB( p );

        FOR(i,0,(int)mat[p].size()-1)
        {
            int x = mat[p][i];

            if(sota.find( x ) == sota.end())
            {
                if(!ase[x]) sota.insert( x );
            }
            else
            {
                sota.erase( x );
            }
        }
    }

    if(prin.size() == n)
    {
        cout << "YES" << endl;;
        FOR(i,0,n-1) cout << prin[i] << endl;
    }
    else cout << "NO" << endl;

    return 0;
}

