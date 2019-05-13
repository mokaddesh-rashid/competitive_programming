#include<iostream>


using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    long long int n,x,a,i,b,minn;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a;

        if(i==0)
        {
            minn=a;
            x=i+1;
            b=1;
        }
        else if(minn==a)
        {
            b++;
        }
        else if(minn>a)
        {
            minn=a;
            x=i+1;
            b=1;

        }


    }

    if(b==1)
        cout<<x;
    else
        cout<<"Still Rozdil";




}
