#include<iostream>

using namespace std;

int main()
{
    int arr[10]={1,4,4,4,4,4,4,4,4,4};

    int mid,start=0,end0=9,a;

    cin>>a;

    mid=(start+end0)/2;

    while(start<end0)
    {
        if(arr[mid]<a)
            start=mid+1;

        else if(arr[mid]>=a)
            end0=mid;

         mid=(start+end0)/2;


    }

    if(start>end0)
        cout<<"no";

    else
        cout<<mid;


}
