#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, k, t, n, a[] = {1, 2, 3, 4,5,6,7,8},count0=0;

    n = 8; // 4 elements

    t = pow(2, n);

    for(i = 1; i < t; i++) // start from 1
    {
         for(k = 0; k < n; k++)
        {
            if(i & (1 << k))
                cout << a[k] << " ";
                count0++;
        }

        cout << "\n";
    }

    cout<<count0;

    return 0;
}
