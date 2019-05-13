#include<bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a, b, sizeof(a))
#define FOR(i,j,k) for(int i = j; i <= k; i++)
typedef long long LL;
const int MAX = 200005;
const int M = (1e9) + 7;


int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    FOR(i,1,15)
    {
        FOR(j,i+1,15)
        {
            int x = i ^ j;
            if(__builtin_popcount(x) == 1) cout << i << ' ' << j << endl;
        }
    }

    return 0;
}
