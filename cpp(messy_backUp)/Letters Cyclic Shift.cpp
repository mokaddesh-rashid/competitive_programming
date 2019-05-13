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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;
string str;

void funk( int x )
{
    char ch;
    int i, j, a, b, n;
    n = str.size();
    for( i=x; i<n; i++ )
    {
         if( str[i] != 'a' )
        {
            a = str[i]-1;
            ch = a;
            str[i] = a;
        }
        else
            return;
    }

    return;
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c, d;

    cin >> str ;

    n = str.size();
    for( i=0; i<n; i++ )
    {
        if( str[i] != 'a' )
        {
            funk(i);
            break;
        }
        else if( i == n-1 )
        {
            str[i] = 'z';
        }
    }

   cout << str;




    return 0;

}


