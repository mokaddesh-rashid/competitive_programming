#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,a,s=0,e=n-1,m;

    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<endl;
    cin>>a;

     m=(s+e)/2;

    while(s<e)
    {
        if(arr[m]==a)
            e=m;
        else if(a>arr[m])
            s=m+1;
        else if(a<arr[m])
            e=m-1;

         m=(s+e)/2;

    }

    cout<<m;
}
//13
//1 2 2 3 4 5 6 6 9 10 11 11 11

