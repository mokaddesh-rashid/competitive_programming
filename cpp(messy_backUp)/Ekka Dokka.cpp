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

    while(t--)
    {
        long long int p, l, q, x=0, i, j, a=1, b=1, c, w;

        cin >> w;

      while( w%2 == 0 )
      {
          w /= 2;
          a *= 2;
      }


    if( a == 1 )
        cout<<"Case "<<ca<<": Impossible\n";

    else
    {
         cout<<"Case "<<ca<<": "<<w <<' '<<a<<endl;

    }
    ca++;

    }


}


