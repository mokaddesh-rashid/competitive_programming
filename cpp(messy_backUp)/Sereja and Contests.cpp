#include<iostream>


using namespace std;

int main()
{
    int arr[4444]={0},x,n,a,b,c,d;

    cin>>x;

    arr[x]++;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==2)
            a=1;
        else
            a=2;

        for(int j=0;j<a;j++)
        {
            cin>>b;
            arr[b]++;
        }
    }
    a=0;
    b=0;
    for(int i=1;i<x;i++)
    {
        if(arr[i]==0)
            a++;
    }
    for(int i=1;i<x;i++)
    {
        if(arr[i]==0&&arr[i+1]==0)
           {
               b++;
               i++;
           }
        else if(arr[i]==0)
        {
            b++;
        }
    }

    cout<<b<<' '<<a;
}
