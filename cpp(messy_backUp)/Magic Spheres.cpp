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


    long long int a, b, c, x, y, z, i, j, l=0, ex=0;

    cin >> a >> b >> c;

    cin >> x >> y >> z;


    if(a >= x)/// = hole ki krbo
    {
       a = a-x;


       ex += (a/2);
    }

    else
    {
       a = x-a;

       l += a;
    }

    if(b >= y)// = hole ki krbo
    {
       b = b-y;


       ex += (b/2);
    }

    else
    {
        b = y-b;



       l += b;
    }

    if(c >= z)// = hole ki krbo
    {
       c = c-z;


       ex += (c/2);
    }

    else
    {
        c = z-c;
        l += c;
    }

    if(ex>=l)
        cout<<"Yes";
    else
        cout<<"No";









}

