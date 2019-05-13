#include<iostream>

using namespace std;

int main()
{
    int n;


    cin>>n;


    int arr[5001]={0},a,b,c,d,i,x=0;

    for(i=0;i<n;i++)
    {
        cin>>a;
        arr[a]++;
    }

     for(i=1;i<=n;i++)
    {
        if(arr[i]==0)
            x++;
    }

    cout<<x;
}
