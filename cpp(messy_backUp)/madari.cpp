#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)

const int MAX = 2000010;

typedef long double LD;


int n;
LD pip[35];

double preCal()
{
    FOR(i,1,32) pip[i] = pow(2, -i);
    double old = 0, notun = 0;

    for(int p = 2*n - 1; p >= n; p--)
    {
        notun = 0;
        int val = 0, v = 1;
        for(int i = 1;;i++)
        {
            double x = pip[i]; val += v;
            notun += (double)x * (i + old);
            if(val >= p)
            {
                notun += (double)x * i;
                break;
            }
            v *= 2;
        }
        old = notun;
    }

    return old;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("out.txt", "w", stdout);
    FOR(i,1,32) pip[i] = pow(2, -i);

    cin >> n;
    cout << fixed;
    cout << setprecision(9) << preCal( ) << endl;
    return 0;
}
