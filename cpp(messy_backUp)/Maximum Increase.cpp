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


//set<int>::iterator ii;

int arr[1000010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 1, y = 0, n, m;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> arr[i];
        if( i > 0 && arr[i] > arr[i-1] )
            x++;
        else
            x = 1;

        y = max( x, y );
    }

    cout << y;

    return 0;

}

