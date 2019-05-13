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

     int t, ca=1;

     cin >> t;


     while( t-- )
     {
         int n=0, a, i;


         for( i=0; i<13; i++)
         {
             cin >> a;

             if( a == 0 )
                n=1;
         }

         if( n==0)
            cout<<"Set #"<<ca<<": Yes\n";
         else
            cout<<"Set #"<<ca<<": No\n";

            ca++;

     }



}

