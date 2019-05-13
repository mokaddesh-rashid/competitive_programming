#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> p_i;


//set<LL>::iterator ii;

int  arr[10000+1];
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number

void sieve( int n )
{
    int  m = sqrt(n), i, j;
    //prime[np] = 2;
   // np++;
    for( i=2; i<=m; i ++)
    {
        if( arr[i] == 0 )
         {
            for( j=i ; j<=n; j += i )
                arr[j] = i ;
         }
    }
    for( i=3 ; i <= n; i += 2)
    {
        if( arr[i] == 0 )
            arr[i] = i;
    }
}

int mat[1010][1010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    sieve(10000);

    int i, j, x, y, n, m, a, b, c, k, z;
    n = 1001;

    for( i=0; i<n; i++ )
        for( j=0; j<n; j++ )
            mat[i][j] = maxx;

        for( i=2; i<=n; i++ )
        {
            m = i;
            while(m>1)
            {
                a = arr[m];
                //cout << i << ' ' << a << endl;
                if( i+a < 1001 && a != i )
                mat[i][i+a] = 1;
                m /= arr[m];
            }

        }

//        for( i=0; i<20; i++ )
//        {
//            for( j=0; j<20; j++ )
//                cout << mat[i][j] << ' ';
//            cout << endl;
//        }

        for( k=0; k<n; k++ )
            for( i=0; i<n; i++ )
                for( j=0; j<n; j++ )
        {
             if( mat[i][k]+mat[k][j] < mat[i][j] )
             {
                 mat[i][j] = mat[i][k]+mat[k][j];
             }
        }



        cin >> m;

        for( i=0; i<m; i++ )
        {
            cin >> a >> b;
            cout << "Case " << i+1 << ": ";
            if( a == b ) cout << 0 << endl;
            else if( mat[a][b] == maxx ) cout << "-1" << endl;
            else cout << mat[a][b] << endl;

        }

    return 0;

}


