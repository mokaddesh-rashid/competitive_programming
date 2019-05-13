
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

    string str, cmp;

    char ch;

    int i;

    cin >> str;

    cmp = str;

    for( i=str.size()-1;i >= 0; i--)
    {
       if( i == str.size()-1 )
       {
           ch = str[i];
       }
       else if(ch < str[i])
       {
            ch = str[i];
       }

       cmp[i] = ch;
    }

    for(i=0;i<str.size();i++)
    {
        if(str[i]==cmp[i])
            cout<<str[i];
    }



}
