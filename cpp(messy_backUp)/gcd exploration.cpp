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

    //cout <<  __gcd((long long int)111,(long long int)1111);


    long long  int i, j, a, b, x, n;

    cin >> str;

    cin >> a >> b;

   x = __gcd((long long int)a,(long long int)b);

   for( i=0; i<x; i++)
   {
       cout<<str;
   }



}

