#include<iostream>

using namespace std;

int main()
{
    double a,start=0,end0, mid;



    cin >> a;

    end0 = a ;

    while(  end0 - start > .00001 )//mid * mid != a abr start < end desi tao hoy naaah
    {
        mid = ( start + end0 ) / 2;

        if(mid * mid > a)
        {
            end0 = mid;
        }

        else if (mid * mid < a)
        {
            start = mid;

        }


    }

    cout<<mid;


}
