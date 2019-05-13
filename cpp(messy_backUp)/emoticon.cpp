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

    int i, j, x = 0, y, n, m ;

    string str;

    cin >> str;

    n = str.size();


    int  st = 0, re = 0,  ss = 0, tt = 0;


    for( i = n-1 ; i >= 0 ; i-- )
    {
        if( str[i] == '_' && tt - ss > re - st )
        {
           re++;

        }
        else if( str[i] == '^' && st != re )
        {
            x++;
            st++;
            ss++;
        }
        else if( str[i] == '^'  )
        {
            tt++;
        }

    }

    cout << x;



    return 0;

}

