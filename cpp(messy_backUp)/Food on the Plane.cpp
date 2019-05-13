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
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;

string str;

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m, a, b, c;

    cin >> str ;

    n = str.size();

    for( i=0; i<n-1; i++ )
    {
        a = str[i]-'0';
        if( x == 0 ) x = a;
        else x = x*10, x += a;

    }

    a = x/4;
    if( x%4 == 0 )a--;

    a = a*2;
    a = a + ( (x+1) % 2 );
    a *= 6;
    b = ( x%4 );

    if( b == 0 || b == 3 )
    {
        c = x-3;
        a += c;
    }
    else
    {
        c = x-1;
        a += c;
    }

    if( str[n-1] == 'f' )  a += 1;
    else if( str[n-1] == 'e' )  a += 2;
    else if( str[n-1] == 'd' )  a += 3;
    else if( str[n-1] == 'a' )  a += 4;
    else if( str[n-1] == 'b' )  a += 5;
    else if( str[n-1] == 'c' )  a += 6;

    cout << a << endl;


    return 0;

}


