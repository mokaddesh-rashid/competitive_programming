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


//set<int>::iterator ii;

int ar[10000];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> ar[i];
    }

    if( n == 1 && ar[0] == 0 )
        cout << "UP";
    else if(  ar[n-1] == 0 )
        cout << "UP";
    else if(  ar[n-1] == 15 )
        cout << "DOWN";
    else if( n == 1 )
        cout << -1;
    else
    {

        if( ar[n-1] == 15 )
            cout << "DOWN";
        else if( ar[n-1] == 0 && ar[n-2] == 1 )
            cout << "UP";
        else if( ar[n-1] > ar[n-2] )
            cout << "UP";
        else if( ar[n-1] < ar[n-2] )
            cout << "DOWN";
    }

    return 0;

}


