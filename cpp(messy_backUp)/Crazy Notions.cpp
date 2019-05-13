#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000
#define mod          1000000009


//set<int>::iterator ii;

long long int  bm(long long int  base, int power, int modu)
{    //bm represents bigmod
    if(power == 0)
    {
        return 1;
    }
    if(power % 2 == 0)
    {
        /*
        int ret = bm(base, power / 2, modu);
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

    //inf;
    //outf;

    long long i, j, x = 1, y, n, m;


    while( x < 100 )
    {
        n = 0;
        n += bm(1,x,mod);
        n += bm(2,x,mod);
        n += bm(3,x,mod);
        n += bm(4,x,mod);

        cout << x << ' ' << n << endl;
        x++;
    }


    return 0;

}


