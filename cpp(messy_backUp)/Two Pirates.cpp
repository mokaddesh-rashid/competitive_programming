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

    long long int n;

    cin>>n;

    long long int arr[n+1],i,j,a=0,b=0,c,d,x=0,y=0;

    for(i=0;i<n/2;i++)
    {
        cin>>a>>b;

        x=x+max(a,b);
        y=y+min(a,b);
    }

    if(n%2)
    {
        cin>>a;
        x+=a;
    }

    cout<<x<<' '<<y;





}

