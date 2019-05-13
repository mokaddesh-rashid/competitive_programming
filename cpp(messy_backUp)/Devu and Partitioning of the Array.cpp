#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
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
#define F first
#define S second
typedef pair<int,int> pr;

vector<int> even, odd;

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, k, a, b, c, no, ne, chk = 0, sm = 0;

    cin >> n >> m >> k;

    FOR(i,0,n-1)
    {
        cin >> x;
        if( x%2 ) odd.PB(x);
        else even.PB(x);
        sm++;
    }

    x = m-k;
    y = k;
    no = odd.size();
    ne = even.size();

    if( no < x ) chk = 1;
    c = (no-x);
    if( c%2 == 1 ) chk = 1;
    if( ne+(c/2) < k ) chk = 1;

    if( chk == 1 ) cout << "NO";
    else if( k == 0 )
    {
        cout << "YES" << endl;
        j = 0;
        FOR(i,0,x-2)
        {
           cout <<  1 << ' ' << odd[i];
           sm--;
           j++;
           cout << endl;
        }
        cout << sm << ' ';
        FOR(i,j,no-1) cout << odd[i] << ' ';
        FOR(i,0,ne-1) cout << even[i] << ' ';
    }
    else
    {
        cout << "YES" << endl;
        int v, lol;
        j = 0;
        FOR(i,0,x-1)
        {
           cout <<  1 << ' ' << odd[i];
           sm--;
           j++;
           if( i == x-1 && k == 0 ) continue;
           cout << endl;
        }

        v = 0;
        while( j < no && v+1 < k )
        {
            cout << 2 << ' ' << odd[j] << ' ' << odd[j+1] << endl;
            j += 2;
            v++;
            sm--;
            sm--;
        }
        lol = j;

        j = 0;
        FOR(i,v,k-2)
        {
            cout << 1 << ' ' << even[j] << endl;
            j++;
            sm--;
        }

        if( sm > 0 && v < k ) cout << sm << ' ';
        FOR(i,j,ne-1)
        {
           cout << even[i] << ' ';
        }
        FOR(i,lol,no-1)
        {
           cout << odd[i] << ' ';
        }
    }

    return 0;

}


