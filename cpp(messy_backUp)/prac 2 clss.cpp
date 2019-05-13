#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define MAX 410

int cumSum[MAX][MAX], n, m, k;
string str[MAX];

int getSum(int x1,int x2,int y1,int y2)
{
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);

    int ret = cumSum[x2][y2];
    if(x1) ret -= cumSum[x1 - 1][y2];
    if(y1) ret -= cumSum[x2][y1 - 1];
    if(x1 && y1) ret += cumSum[x1 - 1][y1 - 1];

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    FOR(i,0,n-1)
    {
        int c = 0, v;
        FOR(j,0,m-1)
        {
            cin >> v; c += v;
            cumSum[i][j] = c;
        }
    }

    FOR(i,1,n-1)
        FOR(j,0,m-1)
            cumSum[i][j] += cumSum[i - 1][j];
    cout << endl;
    FOR(i,0,n-1)
    {
        FOR(j,0,m-1) cout << cumSum[i][j] << ' ';
        cout << endl;
    }
    int x1, y1, x2, y2;
    for(;;)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << getSum(x1, x2, y1, y2) << endl;
    }

    return 0;
}
