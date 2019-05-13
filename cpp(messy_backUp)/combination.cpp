
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, k, t, n, a[] = {1, 2, 3, 4};

    n = 4; // 4 elements

    t = pow(2, n);

    for(i = 1; i < t; i++) // start from 1
    {
        for(k = 0; k < n; k++)
        {
            if(i & (1 << k))
                cout << a[k] << " ";
        }

        cout << "\n";
    }

    return 0;
}
