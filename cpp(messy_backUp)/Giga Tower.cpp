#include<iostream>
#include<string>

using namespace std;

int main()
{
    long long int num,i,time=0,a,b=0;

    cin>>num;

    while(b!=8)
    {
        num++;
        a=num;

        if(a<0)
            a*=-1;

        while(a>0)
        {
           b=a%10;

           if(b==8)
                break;
           a/=10;
        }
        time++;

    }

    cout<<time;
}
