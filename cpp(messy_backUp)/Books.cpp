#include<iostream>
#include<algorithm>


using namespace std;

int bi_search(long long int arr[],long long int start,long long int num,long long int endd)
{
    long long int mid;
   // cout<<"here";
    while(start<=endd)
    {
        mid=(start+endd)/2;

        if(arr[mid]==num)
           break;
        else if(arr[mid]<num)
            start=mid+1;
        else if(arr[mid]>num)
            endd=mid-1;
    }

    if(arr[mid]>num)
        mid--;
    if(arr[mid]>num)
        mid--;
    if(arr[mid]>num)
        mid--;
     //cout<<mid<<endl<<endl;
    return mid;
}

int main()
{
    long long int n,t;

    cin>>n>>t;

    long long int arr[n+1],book[n+1],maxx=0,x=0,i,a,k;


    for(i=0;i<n;i++)
    {
        cin>>arr[i];

        if(i==0)
            book[i]=arr[i];
        else
            book[i]=arr[i]+book[i-1];
    }
    a=t;


       // for(int x=0;x<n;x++)
           // cout<<book[x]<<' ';
    //cout<<endl<<endl;

    for(i=0;i<n;i++)
    {

       // cin>>a
       //cout<<a<<' '<<i<<' ';


        k=bi_search(book,0,a,n-1);
       // cout<<arr[i]<<' '<<book[k]<<endl;
        a+=arr[i];
        k=k-i+1;
        maxx=max(k,maxx);
    }

    cout<<maxx;



}
