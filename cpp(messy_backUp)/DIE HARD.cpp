#include<iostream>

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t>0)
    {
        long long int h,a,time=0;

    cin>>h>>a;

    for(int i=0 ;i>=0;i++ )
    {
        if(h<=0||a<=0)
            break;

        if(i%2==0)
        {
            h+=3;
            a+=2;
            if(h>0&&a>0)
            time++;
        }

        else
        {
            if(h>a&&h>20)//enter into the fire
            {

             // cout<<i<<' '<<1<<endl;
                h-=20;
                a+=5;
            if(h<=0||a<=0)
            break;
            if(h>0&&a>0)
            time++;
            }
            else//enter into the water
            {
               // cout<<i<<' '<<23<<endl;

                h-=5;
                a-=10;
               if(h<=0||a<=0)
            break;
            if(h>0&&a>0)
            time++;
            }

        }


    }

    cout<<time<<endl;

    t--;
    }
}
