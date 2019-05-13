#include<iostream>

using namespace std;

int main()
{
    int n,x=0,tolal,y=0,ar[5]={0},i,total=0;

    cin>>n;

    for(i=4;i>=1;i--)
    {
        ar[i]=0;
    }

    for(i=0;i<n;i++)
    {
        cin>>x;
        ar[x]++;

    }

    for(i=4;i>=1;i--)
    {
        cout<<ar[i];
    }


    for(i=4;i>=1;i--)
    {
        if(i==4)
        {
            total+=ar[i];
        }
        if(i==3)
        {
            total+=ar[i];
            ar[1]=ar[1]-ar[i];

            if(ar[1]<0)
                ar[1]=0;

        }

        if(i==2)
        {
            total+=(ar[i]/2);
            if(ar[i]%2)
                total++;

            ar[1]-=2;

            if(ar[1]<0)
                ar[1]=0;
        }

        if(i==1)
        {
            x=ar[i];
            total+=x;

            cout<<x<<endl;

            if(ar[i]%4)
                total++;
        }
    }

    cout<<total;



}
