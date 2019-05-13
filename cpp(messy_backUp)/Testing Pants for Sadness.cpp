
#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long int n, x=0;

    cin >> n;

    long long int i, j, a=1, b, c;


    for( i=0; i<n; i++,a++)
    {
      cin >> b;

      b--;

      x += (1 + b*a);
    }

    cout << x;



}
