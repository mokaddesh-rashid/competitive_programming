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

    long long int d1,d2,d3,x,a,b,c;

    cin>>d1>>d2>>d3;

    x= d1+d1+d2+d2;
    x= min(d1+d2+d3,x);
    x= min(x,d1+d3+d3+d1);
    x= min(x,d2+d3+d3+d2);


    cout<<x;



}

