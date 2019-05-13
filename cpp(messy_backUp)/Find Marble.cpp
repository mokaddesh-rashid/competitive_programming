#include<iostream>
#include<cmath>
#include<algorithm>


using namespace std;

int main()
{
    int n,s,t;

    cin>>n>>s>>t;

    int arr[n+1],sw[n+1],i,a,b,c=-1;

    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    a=s;

    for(i=0;i<=n;i++)
    {

        if(a==t)
        {
             c=i;
             break;
        }
        a=arr[a];
        //cout<<a<<endl;


    }

    cout<<c;


}
