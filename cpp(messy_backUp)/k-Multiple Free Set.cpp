#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n,k;

    cin>>n>>k;

    long long int i,arr[n+1],mem[10*10*10*10*10*10]={0},a,b,x=0,maxx=0,start,mid,last;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];

    }

    sort(arr,arr+n);


    for(i=n-1;i>=0;i--)
    {
        if(mem[i]==0)
        {
        start=0;
        last=n-1;
        a=arr[i]/k;

        if(arr[i]%k!=0)
            x++;

        else
        {
             while(start<=last)
        {
            mid=(start+last)/2;

            if(arr[mid]==a)
                break;
            else if(arr[mid]>a)
                last=mid-1;
            else if(arr[mid]<a)
                start=mid+1;
        }

        if(start<=last)
        {
            mem[mid]++;
            x++;
            //cout<<arr[i]<<' '<<arr[mid]<<endl;
        }

        else
            x++;



        }
        }
    }

    cout<<x;
}
