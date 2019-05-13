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

    int t, ca=1;

    cin >> t;

    while(t--)
    {
        long long int p, l, q, x=0, i, j, a=1, b=1, c, w, n, arr[1000000+5]={0}, brr[1000000+5]={0};

        cin >> n;

        for( i=0; i<n; i++)
        {
            cin >> a;
            a++;

            if( arr[a] == 0 )
            {
                x += a;
                arr[a] = a;
                brr[a]++;
            }
            else
            {
                brr[a]++;
            }

             if(brr[a]>arr[a])
            {
                x += a;
                //arr[a]++;
                brr[a]=1;
            }

        }



         cout<<"Case "<<ca<<": "<<x<<endl;


    ca++;

    }


}


