#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


int recur( int n, int a, int b)
{
    cout << a<<' ';

    if( n == 0 || n > 10 )
        return 0;

    //recur( n-1, b, a+b);
    recur( n+1, b, a+b);


}

int main()
{
    ios::sync_with_stdio(false);

      int i, n, a = 0, b = 1;

      cin >> n;

      recur( n, a, b);




}

