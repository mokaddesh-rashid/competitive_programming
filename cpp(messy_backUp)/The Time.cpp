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
#define MAX 200005

int sz;
pii p[MAX];

int bs(int v)
{
    int low=0,high=sz-1,mid,x=sz-1;

    while(low <= high)
    {
        mid = (low+high)>>1;

        if(p[mid].xx == v) return mid;
        else if(p[mid].xx > v)
        {
            high = mid-1;
            x = mid;
        }
        else low = mid+1;
    }

    return x;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    std::ios_base::sync_with_stdio(0);
    int n, i, j, k, cnt, l, r, x;
    bool flag;

    cin >> n >> k;

    x = -1;
    sz = 0;

    FOR(i,0,n-1)
    {
        cin >> j;
        if(j != x) p[sz++] = mp(i+1,j);
        x = j;
    }

    p[sz] = mp(n+1, p[sz-1].yy);

    while(k--)
    {
        cin >> l >> r >> x;

        j = bs(l);
        flag = false;

        FOR(i,max(0,j-2),min(j+2,sz))
        {
            if(p[i].xx >= l && p[i].xx <= r && p[i].yy != x)
            {
                cout << p[i].xx << NL;
                flag = true;
                break;
            }
            if(i > 0 && p[i-1].xx <= l && p[i].xx > l && p[i-1].yy != x)
            {
                cout << l << NL;
                flag = true;
                break;
            }
        }

        if(!flag) cout << -1 << NL;
    }

    return 0;
}
