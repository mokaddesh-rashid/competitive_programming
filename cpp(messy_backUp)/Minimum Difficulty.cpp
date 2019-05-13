
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,a,b,c=0,x,y,m;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(i=1;i<n-1;i++)
    {
        b=0;
      for(x=1;x<n;x++)
    {
        if(x==i)
            continue;
        else
        {
            int k,l;
            k=x;
            l=x-1;
            if(l==i)
                l--;
           a=arr[k]-arr[l];
           //cout<<arr[k]<<' '<<arr[l]<<endl;
           //cout<<a<<endl;
        }
        b=max(b,a);
       // cout<<b<<endl;
    }
    //cout<<"what the fuck \n";
    if(i==1)
        c=b;
    else
      c=min(b,c);
    }
    cout<<c;
}
