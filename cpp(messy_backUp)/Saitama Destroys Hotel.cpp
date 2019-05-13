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

    int n, s;

    cin >> n >> s;

    int arr[1111]= {0},i,j,a,b,c=0,x=0;

    for( i=0; i<n; i++)
    {
       cin >> a >> b;

       arr[a] = max(arr[a],b);
    }


    for( i = s; i>0; i--,c++)
    {
        c = max(arr[i],c);
    }

    cout << c;



}

