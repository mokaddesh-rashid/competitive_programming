#include<bits/stdc++.h>

#define FOR(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

const int MAX = 200010;

map<int, int> mp;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gV(int v = (1e9)) {return rng() % v;}
int ara[MAX], id[MAX];

int main()
{
    freopen("in.txt", "w", stdout);

    int tc = 61;
    cout << tc << endl;
    FOR(tt,1,tc)
    {
        int n = gV(10) + 1;
        cout << n << endl;
        FOR(i,1,n)
            ara[i] = gV() + 1, id[i] = i;

        sort(id + 1, id + n + 1,[](int x,int y)
             {
                 return ara[x] < ara[y];
             });

        FOR(i,1,n)
        {
            int j;
            for(j = i + 1; j <= n; j++)
                if(id[i] < id[j]) break;
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
