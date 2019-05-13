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

    int n, k;

    cin >> n >> k;


    int neg[n+1], i, j, x=0, a=0, b, minn=-1;


    for( i=0; i<n; i++)
    {
        cin >> b;

        if( b < 0 )
        {
            neg[a] = b;
            a++;
        }
        else
            {
                x += b;
                if( minn == -1)
                    minn = b;

            }
    }

    sort(neg,neg+a);

    for( i=0; i<a; i++)
    {
        b=neg[i];

         if(i==a-1&&k%2==0&&((b*-1)<minn||minn==-1))
         {
             //cout << i <<endl;
             x += b;
             k=0;
         }

         else if( 0 < k)
        {
            b *=-1;
            x += b;
            k--;
        }

        else
            x += b;

    }

    if(k!=0 && k%2 )
        x -= (minn+minn);

    cout << x;





}

