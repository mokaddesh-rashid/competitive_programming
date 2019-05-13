#include<iostream>

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t>0)
    {
        int n;

        cin>>n;

        int arr[n+1],i,x,a=0;

        for(i=0;i<n;i++)
            cin>>arr[i];

        for(i=0;i<n;i++)
            for(x=1;x<n;x++)
        {
            if(arr[x]<arr[x-1])
            {
                swap(arr[x],arr[x-1]);
                a++;
            }
        }



        cout<<"Optimal train swapping takes "<<a<<" swaps."<<endl;

        t--;
    }
}
