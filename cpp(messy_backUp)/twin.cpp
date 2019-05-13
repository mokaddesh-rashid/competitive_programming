#include<iostream>

using namespace std;

int main()
{
    int i,n,a=0,b=0,c,x=0,ar[111],m;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        x+=ar[i];
    }
    x/=2;

    for(i=0;i<n;i++)
    {
       for(m=0;m<n;m++)
       {
           if(ar[i]>ar[m])
            swap(ar[i],ar[m]);
       }
    }
    i=0;
    while(a<=x)
    {
        a+=ar[i];
        i++;
        b++;
    }

    cout<<b;
}
