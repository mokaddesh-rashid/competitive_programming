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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int, int>  pr;

//set<int>::iterator ii;

class compare
{
public:
    bool operator()(pr x, pr y)
    {
        if( x.first > y.first ) return true;
        else
            return false;
    }
};
priority_queue< pr, vector< pr >, compare > p_q;
//pair<int,int> pr;
pr pra;


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m;

    pra = make_pair(1,2);

    p_q.push(pra);
    p_q.push(make_pair(3,2));

    cout << p_q.top().first;

      p_q.pop();

    return 0;

}


