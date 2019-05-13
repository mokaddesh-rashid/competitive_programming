#include<iostream>

using namespace std;

int main()
{
    int ar[8],i,n,a,b,x=-1;

    for(i=0;i<6;i++)
        cin>>ar[i];

    for(i=0;i<6;i++)
        for(n=0;n<6;n++)
    {
        if(ar[i]<ar[n])
            swap(ar[i],ar[n]);
    }

    for(i=0;i<6;i++)
    {
        if(ar[i]==ar[i+1]&&ar[i+1]==ar[i+2]&&ar[i]==ar[i+2])
        {
            x=i;
            break;
        }
    }


    if(x==-1)
        cout<<"Alien";

    else if(x==0)
    {
        if(ar[4]==ar[5])
            cout<<"Elephant";
        else
            cout<<"Bear";
    }
    else  if(x==1)
    {
        if(ar[0]==ar[5])
            cout<<"Elephant";
        else
            cout<<"Bear";
    }

    else
         if(x==2)
    {
        if(ar[0]==ar[1])
            cout<<"Elephant";
        else
            cout<<"Bear";
    }
}
