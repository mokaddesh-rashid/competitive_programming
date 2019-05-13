#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int flower[n+1],i,a,b,x=0,y=0,z=0,ma,mi;

    for(i=0;i<n;i++)
    {
        cin>>flower[i];

        if(i==0)
        {
            a=flower[i];
            b=flower[i];
            x++;
            y++;
        }

        else
        {
            if(a>flower[i])
            {
                a=flower[i];
                x=0;
            }
            if(b<flower[i])
            {
                b=flower[i];
                y=0;

            }
            if(a==flower[i])
                x++;
            if(b==flower[i])
                y++;
        }
    }

     //cout<<x<<endl<<y<<endl;
    cout<<b-a<<' ';
    cout<<x*y;

}
