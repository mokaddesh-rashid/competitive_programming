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

    long long int n, i, j, a, b, c,maxx=0, d;

    cin >> n;
   // n--;

    if( n==1 )
        cout<< 1;
    else if( n == 2 )
        cout << 2;
    else
    {
        int t = 0, s = 0;

        while(n>3 && t<100)
        {
        a = __gcd((n-1),n);

        b = (n-1)*n;

        b /= a;

        d = b;
       // cout << b<<endl;

        maxx = max(b,maxx);
        c=n;
        while(s<10 && c >3)
        {
        b = d;
        a = __gcd((c-2),b);
        //cout << a<<endl;
        b = (c-2)*b;

        b /= a;

         maxx = max(b,maxx);
         s++;
         c--;
        }


        n--;
        t++;

        }

        cout << maxx;

    }




}

