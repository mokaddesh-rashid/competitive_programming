#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],i,a=0,pos,minn,c,x;

     for(i=0;i<n;i++)
       {
            cin>>a;

            x=i;
            while(a<arr[x-1]&&x>0)
            {
                arr[x]=arr[x-1];
                x--;
            }

            arr[x]=a;
       }



     for(i=0;i<n;i++)
        cout<<arr[i]<<' ';


}

