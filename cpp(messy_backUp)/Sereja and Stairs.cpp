#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    int n;

    cin>>n;

    int arr[300000]={0},i,j=0,a,b=0,c,rr[n+1],brr[n+1];

    for(i=0;i<n;i++)
    {
        cin>>rr[i];
        arr[rr[i]]++;

    }
    sort(rr,rr+n);

    for(i=0;i<n;i++)
    {
        if(arr[rr[i]]>1&&brr[j-1]!=rr[i])
        {
            brr[j]=rr[i];
            j++;
        }
    }
    for(i=n-1;i>=0;i--)
    {
        if(arr[rr[i]]>0&&brr[j-1]!=rr[i])
        {
              brr[j]=rr[i];
              j++;
        }
    }

    cout<<j<<endl;

    for(i=0;i<j;i++)
        cout<<brr[i]<<' ';
}
