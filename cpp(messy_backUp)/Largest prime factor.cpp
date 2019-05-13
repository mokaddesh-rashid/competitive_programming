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

    cin >> t;

    while(t--)
    {
        long long int  i, j, a, b, c, d, n, arr[100000+1]={0},prime[100000+1], x=0;

    cin >> a;

    n= sqrt(a);
    n++;
    b=a;
    for(i=2; i<=n; i++)
    {
        if(arr[i]==0)
        {
            //cout<<i<<endl;
            j = i+i;
            prime[x] = i;
            if(a%i==0)
               {
                  b=i;
                  //cout << b <<endl;
               }

            x++;

            while(j <= n)
            {
                arr[j]++;
                j+=i;
            }
        }
    }

    while(true)
    {
        c=0;
        for(i=0;i<x;i++)
        {
            if(a%prime[i]==0)
            {
                c=1;
                a/=prime[i];
            }

        }
        if(c==0)
            break;
    }

    cout<<max(a,b)<<endl;

    }





}
