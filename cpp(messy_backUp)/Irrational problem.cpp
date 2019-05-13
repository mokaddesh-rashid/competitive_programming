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

int main()
{
    ios::sync_with_stdio(false);

    int i, j, x, y = 100000, n, m, a, b;

    cin >> x;
    y = min( y, x);
    cin >> x;
    y = min( y, x);
    cin >> x;
    y = min( y, x);
    cin >> x;
    y = min( y, x);

    cin >> a >> b;

    y = min( y, b+1);


    x = max( 0, y-a);



    cout << x;

    return 0;

}

