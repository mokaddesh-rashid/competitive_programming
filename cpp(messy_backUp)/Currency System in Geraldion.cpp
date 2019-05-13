#include<iostream>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int i,a,b,c,d,arr[n+1],x=0,y=0;

    for(i=0;i<n;i++)
    {
        cin>>a;

        arr[i]=a;

        if(a==1)
           x=1;
        if(a==2)
            y=1;

    }

    if(x==0)
        cout<<1;

    else
        cout<<-1;

}
