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

    cin >> str;

    char ch;

    long long int n;

    n = str.size();

    long long int arr[n+1], i, j, a=0, top = -1, b=0;

    for( i=0; i<n; i++)
    {
        if( str[i] == '(' )
        {
            top++;
            arr[top] = 1;
        }
        else if( str[i] == '{' )
        {
            top++;
            arr[top] = 2;
        }
        else if( str[i] == '[' )
        {
            top++;
            arr[top] = 3;
        }
        else if( str[i] == '<' )
        {
            top++;
            arr[top] = 4;
        }
        else if( str[i] == ')' )
        {
            if( arr[top] != 1 )
                a++;
            top--;
        }
         else if( str[i] == '}' )
        {
            if( arr[top] != 2 )
                a++;
            top--;
        }
         else if( str[i] == ']' )
        {
            if( arr[top] != 3 )
                a++;
            top--;
        }
         else if( str[i] == '>' )
        {
            if( arr[top] != 4 )
                a++;
            top--;
        }
        if( top < -1 )
        {
            b=1;
            break;
        }
    }

    if( b == 1 || top > -1 )
        cout << "Impossible";
    else
        cout << a;





}

