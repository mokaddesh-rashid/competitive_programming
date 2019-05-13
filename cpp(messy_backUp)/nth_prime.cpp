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

    int x=0,i,j,a,b,c,d,arr[10000+1]={0};

    for(i=2;i<=10000;i++)
    {
        if(arr[i]==0)
        {
            x++;
            j=i+i;
            while(j<10000)
            {
                arr[j]++;
                j+=i;
            }
        }
    }

    cout<<x;



}

