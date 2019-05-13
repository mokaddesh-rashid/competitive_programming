#include<iostream>

using namespace std;

int main()
{
    long long int n;

    cin>>n;

    long long int left[n+1],right[n+1],i,x=-1,a,b,c,d;


    for(i=0;i<n;i++)
    {
        cin>>left[i];
        cin>>right[i];

        if(i==0)
        {
            a=left[i];
            b=right[i];
        }

        else
        {
            a=min(a,left[i]);
            b=max(b,right[i]);
        }
    }
     for(i=0;i<n;i++)
    {
        if(a==left[i]&&b==right[i])
        {
            x=i+1;
        }
    }

    cout<<x;
}
