#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,x;

    cin>>n>>x;

    int arr[n+1],a=0,b=n-1,c=0,d,i;

    for(i=0;i<n;i++)
       {
            cin>>arr[i];
            if(x==arr[i])
                c++;
       }

    sort(arr,arr+n);


    while(a<b)
    {
        if(arr[a]+x==arr[b])
        {
            cout<<arr[a]<<' '<<arr[b]<<endl;
            a++;
            c++;

        }
        else if(arr[a]+x>+arr[b])
        {
           a++;
        }
        else if(arr[a]+x<+arr[b])
        {
            b--;
        }
    }
}
