#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long int arr[1999999]={0},i,a,b,x;


    for(i=3;i<=1999999;i++)
    {
        if(i%2==0)
            arr[i]=1;

        if(arr[i]==0)
        {
            a=2;

            while(x<1999999)
            {
                x=i*a;
                arr[x]=1;
                a++;

            }
        }

    }

    int t;
    cin>>t;


    while(t>0)
    {
        cin>>a;

        b=sqrt(a);

        if(a==4)
            cout<<"YES\n";

        else if(arr[b]==0&&b*b==a&&a%2!=0&&a!=1)
            cout<<"YES\n";
        else
            cout<<"NO\n";



       t--;

    }




}
