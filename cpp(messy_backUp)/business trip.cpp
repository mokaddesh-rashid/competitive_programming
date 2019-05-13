#include<iostream>

using namespace std;

int main()
{
    int x,y,a,b,i,ar[111],n,z;

    cin>>a;

    for(i=0;i<12;i++)
        cin>>ar[i];

    x=11;
    for(i=0;i<12;i++,x--)
    {
       for(n=i;n<=x;n++)
       {
           if(ar[i]<ar[n])
            swap(ar[i],ar[n]);
           if(ar[x]>ar[n])
            swap(ar[x],ar[n]);
       }
    }

    //cout<<ar[0]<<endl;
    x=0;
    i=0;
    z=0;
    while(x<a)
    {
        x+=ar[i];
        i++;
        z++;
    }
    if(z>12)
        cout<<-1;
    else
    cout<<z;
}
