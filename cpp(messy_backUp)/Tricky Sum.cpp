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

    cin>>t;

    while(t>0)
    {
        long long int n,x=1,y,a=0,b=0,c=0;

    cin >> n;

    a=n*(n+1);
    a/=2;

    while(x<=n)
    {
       if(x<=n)
       {
           b+=x;
       }
       x*=2;
    }

    a=a-b;

    cout<<a-b<<endl;
    t--;
    }



}

