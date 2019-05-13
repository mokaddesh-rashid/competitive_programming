#include<iostream>
#include<algorithm>


using namespace std;


int main()
{
    long long int n,m;

    cin>>n>>m;

    long long int arr[m+1],i,x,a=0,b,c;

    for(i=0;i<m;i++)
    {
         cin>>arr[i];
         if(arr[i]==1||arr[i]==n)
            a=1;
    }

    sort(arr,arr+m);

    for(i=2;i<m;i++)
    {

         if(arr[i]==arr[i-1]+1&&arr[i]==arr[i-2]+2)
             a=1;
    }

    if(a==0)
        cout<<"YES";
    else
        cout<<"NO";
}
