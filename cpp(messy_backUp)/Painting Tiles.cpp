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
    //ios::sync_with_stdio(false);

    long long int i, j, x, y, n, m, t, ca = 1 ;

    //cin >> t;

    scanf( " %lld" ,&t);

    while( t-- )
    {
        //cin >> n;

        scanf( " %lld" ,&n);

        printf( "Case %lld: ", ca ) ;


        if( n % 7 == 1 ||  n % 7 == 0  ||  n % 8 == 7 || n == 1 || n == 6 )
            printf( "Oh no, my eggs! :( \n" ) ;
        else
            printf( "No eggs for you! :D \n" ) ;

        ca++;


    }

    return 0;

}

