#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 100010
#define F first
#define S second
typedef pair<long long,char> pr;

pr ar[MAX];
long long val[MAX], p;
vector<long long> mat[MAX];
vector<long long> sat[MAX];


int main()
{
    ios::sync_with_stdio(false);
    int n;
    long long c = 0, a = 0, b = 0, d = 0;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> ar[i].F >> ar[i].S;
        if(ar[i].S == 'P') d = 1;
    }
    sort(ar, ar + n);

    p = 0;
    FOR(i,0,n-1)
    {
        if(ar[i].S == 'P') val[p] = ar[i].F, p++;
        else if(ar[i].S == 'R') sat[p].push_back( ar[i].F ), a = ar[i].F;
        else mat[p].push_back( ar[i].F ), b = ar[i].F;
    }

    if(!d)
    {
        long a = -1, b = -1;
        FOR(i,0,n-1)
        {
            if(ar[i].S == 'R')
            {
                if(a != -1) c += (ar[i].F - a);
                a = ar[i].F;
            }
            else
            {
                if(b != -1) c += (ar[i].F - b);
                b = ar[i].F;
            }
        }

        cout << c << endl;
        return 0;
    }

    if(val[p - 1] < a) c += (a - val[p - 1]);
    if(val[p - 1] < b) c += (b - val[p - 1]);

    FOR(i,0,p-1)
    {
        if(i == 0)
        {
            if( mat[i].size() ) c += abs(val[i] - mat[i][0]);
            if( sat[i].size() ) c += abs(val[i] - sat[i][0]);
        }
        else
        {
            long long a = (val[i] - val[i - 1]) * 2, b = (val[i] - val[i - 1]) * 3, x = 0;

            x = 0;
            if(mat[i].size())
            FOR(k,0,(int)mat[i].size())
            {
                if(!k) x = max(x, mat[i][k] - val[i - 1]);
                else if(k == (int)mat[i].size()) x = max(x, val[i] - mat[i][k - 1]);
                else x = max(x, mat[i][k] - mat[i][k - 1]);
            }
            else x = val[i] - val[i - 1];
            b -= x;

            x = 0;
            if(sat[i].size())
            FOR(k,0,(int)sat[i].size())
            {
                if(!k) x = max(x, sat[i][k] - val[i - 1]);
                else if(k == (int)sat[i].size()) x = max(x, val[i] - sat[i][k - 1]);
                else x = max(x, sat[i][k] - sat[i][k - 1]);
            }
            else x = val[i] - val[i - 1];
            b -= x;

            c += min(a, b);
        }
    }

    cout << c << endl;

    return 0;
}
