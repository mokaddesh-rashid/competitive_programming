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

    string str;
    char ch;

    int i, j, a, b, m=0;

    cin >> str;

    for (i=0;i<str.size();i++)
    {
        a = str[i];

        m = max(m,a);
    }

    ch = m;

    for (i=0;i<str.size();i++)
    {
        if( str[i]==ch )
            cout <<ch ;
    }








}

