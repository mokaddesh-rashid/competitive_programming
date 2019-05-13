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

    long long int n,m,x=0,i,j,a,b;

    cin>>n>>m;


    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a>>b;

            if(a==1||b==1)
                x++;
        }
    }

    cout<<x;






}

