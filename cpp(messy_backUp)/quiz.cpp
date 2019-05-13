#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

//set<int>::iterator ii;


using namespace std;

long long int  bm(long long int  base, long long int power, long long int modu) {    //bm represents bigmod
    if(power == 0)
    {
        return 1;
    }
    if(power % 2 == 0)
    {
        /*
        long long int ret = bm(base, power / 2, modu);
        return ret * ret;
        */
        long long int  ret = (bm(base, power / 2, modu));
        return (ret * ret) % modu;
    }
    else
    {
        //return base * bm(base, power - 1, modu);
        return ( base * (bm(base, power - 1, modu)) ) % modu;
    }
}

 int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, x, y, n, m, k, a, b, c, d , e;

    cin >> n >> m >> k ;

    a = n / k;
    b = a * (k-1);
    c = n % k;

    b += c;
    //cout << b << endl;
    d = max ( ( long long )0, m - b );

    //cout << d << endl;

    e = k * 2;

    x = bm( 2, d, 1000000009) - 1;
    //cout << x << endl;
    x = x * e;

    y = d * k;

    y = m - y;

    cout << (x + y) % 1000000009;






    return 0;

}
