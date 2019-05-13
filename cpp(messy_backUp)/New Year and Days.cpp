
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

    string str, ex;

    int x;


    cin >> x >> ex >> str;

    if( str == "week")
    {
        if( x == 5 || x == 6 )
            cout << 53;
        else
            cout << 52;
    }
    else
    {
        if( x==31)
            cout<< 7;
        else if( x==30 )
            cout<< 11;
        else
            cout<< 12;
    }



}
