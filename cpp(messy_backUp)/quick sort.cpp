#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],ok[n+1],i,j,x=0,a,start,last,pivot;

    for(i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    x=0;

   // while(x<=n/2)
    {
        pivot=n/2;
        start=0;
        last=n-1;

        while(start<last)
        {
            if(arr[start]>arr[pivot]&&arr[last]<arr[pivot])
                swap(arr[start],arr[last]);
             if(arr[start]<=arr[pivot])
                start++;
             if(arr[last]>=arr[pivot])
                last--;

            cout<<arr[start]<<' '<<arr[last]<<endl;
        }
        swap(arr[pivot],arr[start]);

     for(i=0;i<n;i++)
    {
       cout<<arr[i]<<' ';

    }

        cout<<endl<<"here";
        x++;
    }


}
