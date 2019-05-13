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


    int n,x=0,a,b,arr[11],c;

    cin>>n;
    n--;

    for(i=0;i<3;i++)
    {
        cin>>c;

        a=7-c;

        arr[c]=a;
        arr[a]=c;

    }

    for(i=0;i<n;i++)
    {
        cin>>c;

        a=7-a;
        if(arr[c]!=a)
            x=1;

    }

}
