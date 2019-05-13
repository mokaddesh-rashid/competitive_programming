#include<iostream>
#include<string>

using namespace std;

int main()
{
    int num,i,a,b,x,time=0,arr[1111];

    cin>>num;

    while(num>0)
    {
        int newnum=0,increase=1;
        a=num;

        while(a>0)
        {
            b=a%10;
            a/=10;

            if(b!=0)
                b=1;
            else
                b=0;

            newnum=newnum+(increase*b);

            increase*=10;


        }

        arr[time]=newnum;
        time++;

        num-=newnum;


    }

    cout<<time<<endl;

    for(i=0;i<time;i++)
        cout<<arr[i]<<' ';

}
