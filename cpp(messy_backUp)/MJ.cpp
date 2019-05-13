#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define LL long long
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 100010

int n, pa[MAX], sz[MAX];
LL prin[MAX], co[MAX], rosa[MAX];
pair<int,int> ar[MAX], id[MAX];

int finPa(int p)
{
    ///cout << p << ' ' << pa[p] << endl;
    return (pa[p] == p) ? p : (pa[p] = finPa(pa[p]));
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> ar[i].F >> ar[i].S;
        cin >> id[i].F; co[i] = id[i].F;
        id[i].S = i;
    }
    sort(id + 1, id + n);
    FOR(i,1,n) pa[i] = i, sz[i] = 1;

    LL q = 1;
    FOR(i,1,n-1)
    {
        while(id[q].F == id[i].F && q < n)
        {
            int p = id[q].S;
            int r1 = finPa( ar[p].F ), r2 = finPa( ar[p].S );
            rosa[r1] = (LL)sz[r1] * sz[r2] * 2;
            ///cout << ar[p].F << ' ' << ar[p].S << ' ' << r1 << ' ' << r2 << endl;
            if(r1 != r2)
            {
                sz[r1] += sz[r2];
                pa[r2] = r1;
            }
            q++;
        }
        ///cout << q << endl;

        int p = id[i].S;
        prin[p] = rosa[ finPa(ar[p].F) ];
    }

    LL val = 0;
    FOR(i,1,n-1) val = max(val, prin[i]);
    vector<int> show;
    FOR(i,1,n-1)
        if(val == prin[i]) show.push_back( i );

    cout << val << ' ' << show.size() << endl;
    for(auto x : show)
    {
        cout << x << ' ';
    }
    //cout << prin[i] << ' ';

    return 0;
}
