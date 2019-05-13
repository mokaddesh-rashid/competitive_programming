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

    int n;

    cin >> n;

    int arr[n+1], i, j, a, b=0, c=0;

    for( i=0; i<n; i++)
    {
        cin >> a;

        if(a==1)
            c=1;

        if(c==0)
           b++;
    }

    cout << b;



}

