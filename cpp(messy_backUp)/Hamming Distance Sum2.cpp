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

    string str, ss;

    cin >> str >> ss;

    long long int i, j, a, b, c=0, d, x=0, y=0, z, arr[20000+2]={0},brr[20000+20]={0}, l, m, n;

    for (i=0; i<ss.size(); i++)
    {
        a = ss[i]-48;

        if( a == 1 )
            x++;
        else
            y++;

        arr[i] = x;
        brr[i] = y;

    }

    if( ss.size() >= str.size())
    {
        for (i=0; i<str.size(); i++)
    {
        a = str[i]-48;

        if( a == 0 )
           {
              l = str.size() - i - 1;
              m = ss.size() - l;

             if(i>0)
                 x = arr[i-1];
              else
                 x = 0;
              y = arr[m];

              c += (y-x);
           }
        else
        {

              l = str.size() - i - 1;
              m = ss.size() - l;

             if(i>0)
                 x = brr[i-1];
              else
                 x = 0;
              y = arr[m];

              c += (y-x);

        }




    }

    }

    cout << c;





}


