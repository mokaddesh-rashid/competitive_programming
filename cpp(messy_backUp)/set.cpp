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
#define PB push_back
#define FF first
#define SS second
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



struct node
{
    int x, y, z;
};

class compare
{
public:
    bool operator()( node f, node s )
    {
        if( f.x == s.x && f.y == s.y ) return f.z < s.z;
        else if( f.x == s.x ) return f.y < s.y;
        return f.x < s.x;
    }
};


set<node,compare> ms;
set<node>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m;
    node damn;

    damn.x = 0;
    damn.y = 1;
    damn.z = 2;


    ms.insert( damn );
    damn.z = 4;
    ii = ms.find( damn );
    node chk;
    chk = *ii;

    cout << chk.x << ' ' << chk.y;


    return 0;

}


