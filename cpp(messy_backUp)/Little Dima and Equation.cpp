#include<iostream>
#include<cmath>

using namespace std;

int s(long long int x)
{
    if(x==0)
        return 0;
    else
        return x%10+s(x/10);
}

int main()
{
   long long int a,b,c,x,arr[11111],top=0,y,z,t;

    cin>>a>>b>>c;

     for(x=1;x<=81;x++)
    {
        y=x;
        z=1;
        t=a;
        while(t>0)
        {
            z=z*y;
            t--;
        }
        y=z;
       // cout<<y<<endl;
        y*=b;
        //cout<<y<<endl;
        y+=c;
        //cout<<y<<endl;

        //cout<<s(x)<<endl;
    }


     cout<<top<<endl;
     for(int i=0;i<top;i++)
        cout<<arr[i]<<' ';
}


