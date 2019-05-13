#include<iostream>

using namespace std;

int main()
{
    int arr[10]={1,3,5,7,8,8,8,9,9,11};

    int a,start=0,end0=9,mid;

    cin>>a;

    while(start<=end0)
    {
        mid=(start+end0)/2;

        if(arr[mid]<=a)
            start=mid;

        else if(arr[mid]>a)
            end0=mid-1;

         cout<<start<<' '<<end0<<' '<<mid<<endl;
    }

    cout<<mid;
}
