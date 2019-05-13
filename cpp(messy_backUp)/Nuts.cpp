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

    long long int i, j, a, b, k, v, x=0, c, d, s;

    cin>>k>>a>>b>>v;


    while(a>0)
    {
        if(b<=0)
        {
            a-=v;
        }

        else if(k<=b)
        {
           s=k;
           b-=(k-1);
           a-=(k*v);
        }
        else
        {
            s=b+1;
            b=0;
            a-=(s*v);
        }
        x++;
    }
    cout<<x;



}

