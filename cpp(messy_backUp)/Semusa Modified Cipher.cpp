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

     string str ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

     long longa=1, arr[111];

     arr[0] = 1;
     arr[1] = 1;

     for(long longi=2; i < 99; i++)
     {

         arr[i] = (arr[i-1] + arr[i-2]);

         cout << arr[i] << ' ';

     }


     long longt;

     cin >> t;

     while( t-- )
     {
         long longi, j, b, c, n, x=0, y=0;


     cin >> n ;



     for( i=0; i<n; i++)
     {
         x = arr[i];
         cout << str[x-1];


     }

     cout << endl;
     }







}

