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

    long long int i, j, a, b, c, d, x=0, y, z;

    y = str.size();
    z = ss.size();

    if(y<=z)
    {
        for( i=0; i<z; i++)
    {
        for( j=0; j<y; j++)
        {
            if( i+j < z)
            {
            a = str[j]-48;
            b = ss[i+j]-48;

            x += max(a-b,b-a);
            }
        }

        if(i+j >= z)
            break;

    }
    }

    cout << x;



}

