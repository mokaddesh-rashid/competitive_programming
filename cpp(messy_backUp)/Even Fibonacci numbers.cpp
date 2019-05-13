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
    int t;

    cin >> t;

    while(t--)
    {


    unsigned long long int i, j, a=0, b=1, c=2, d, n;

    cin >> n;

    while( c <= n )
    {
        if(c%2==0)
            a+=c;

        d = b;
        b = c;
        c = c+d;


    }

    cout << a <<endl;
    }



}

