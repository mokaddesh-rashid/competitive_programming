#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

int a[MAX]={0};

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    std::ios_base::sync_with_stdio(0);
    int n, i, j, k, cnt, sum;

    cin >> n;

    FOR(i,1,n)
    {
        cin >> k;

        if(a[k-1] == 0)
            a[k] = 1;
        else
        {
            a[k] = 1+a[k-1];
            a[k-1] = 0;
        }
    }

    int mx = 0;

    FOR(i,1,n)
    {
        mx = max(mx, a[i]);
    }

    cout << n-mx << NL;

    return 0;
}
