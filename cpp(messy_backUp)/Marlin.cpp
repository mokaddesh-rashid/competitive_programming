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


int n, k;
int mat[5][100];

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    cin >> n >> k;


    mem(mat, -1);

    if(k%2 == 0)
    {
        int p, q;
        p = q = 1;
        FOR(i,0,k-1)
        {
            if(i%2)
            {
                mat[1][p] = 0;
                p++;
            }
            else
            {
                mat[2][q] = 0;
                q++;
            }
        }
    }
    else
    {
        int p, q, m, l = 0, lo = 0;

        m = n / 2;
        mat[1][m] = 1; k--;
        p = m - 1; q = m + 1;

        FOR(i,0,k-1)
        {
            if(i%2)
            {
                mat[lo + 1][p] = 0;
               // cout << p << endl;

                if(lo == 0) p--;
                else p++;

                if(p == 0) p = 1, lo = 1;

            }
            else if(i%2 == 0)
            {
                if(q == n - 1) q = n - 2, l = 1;
                ///cout << q << endl;
                mat[l + 1][q] = 0;

                if(l == 0) q++;
                else q--;

            }
        }

    }

    cout << "YES" << endl;

    FOR(i,0,3)
    {
        FOR(j,0,n-1)
        {
            if(mat[i][j] == -1) cout << '.';
            else cout << '#';
        }
        cout << endl;
    }

    return 0;
}

