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

    string str,sz;

    cin >> str;


    char ch  = '.', la = '/';


    int i, j, a, b, c, d, e, x=0, arr[200000+2]={0};

    x = str.size();

    for( i=0; i<x-2; i++)
    {
        if( str[i] == str[i+1] && str[i] == str[i+2] )
        {
           arr[i]++;
        }
        else if(str[i-1]==str[i-2])
    }


    if(str.size()<3)
        cout<<str;

    else
     for( i=0; i<str.size(); i++)
    {
        if(la==ch&&str[i]==str[i+1]&&arr[i]==0&&arr[i+1]==0)
        {
           arr[i+1]++;
        }
        if(arr[i]==0)
        {
           cout << str[i];
           la = ch;
           ch =str[i];

        }

    }




}

