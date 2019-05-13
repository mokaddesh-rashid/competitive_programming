#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(long long i=j;i<=k;i++)
#define MAX 300010
#define F first
#define S second
typedef pair<long long,long long> pr;

long long n, k1, k2;
pr ar[MAX];


int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> k1 >> k2;

    FOR(i,0,n-1) cin >> ar[i].F, ar[i].S = i + 1;
    sort(ar, ar + n);

    FOR(i,0,n-1)
    {
        long long x = k1 / ar[i].F;

        if(k1 % ar[i].F) x++;
        long long p = (i + x), cnt = max((long long)0, (n - p));
       /// cout << p << ' ' << cnt << ' ' << ar[p].F << endl;
        if(p < n && cnt * ar[p].F >= k2)
        {
            cout << "Yes" << endl << (p - i) << ' ' << cnt << endl;
            FOR(i,0,p-1) cout << ar[i].S << ' ';
            cout << endl;
            FOR(i,p,n-1) cout << ar[i].S << ' ';
            cout << endl;
            return 0;
        }
    }

    swap(k1, k2);

    FOR(i,0,n-1)
    {
        long long x = k1 / ar[i].F;

        if(k1 % ar[i].F) x++;
        long long p = (i + x), cnt = max((long long)0, (n - p));
        ///cout << p << ' ' << cnt << endl;
        if(p < n && cnt * ar[p].F >= k2)
        {
            cout << "Yes" << endl << cnt << ' ' << (p - i) << endl;
            FOR(i,p,n-1) cout << ar[i].S << ' ';
            cout << endl;
            FOR(i,0,p-1) cout << ar[i].S << ' ';
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
