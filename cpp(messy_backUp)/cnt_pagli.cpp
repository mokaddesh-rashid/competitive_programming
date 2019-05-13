#include<iostream>

using namespace std;

int n, arr[10010];

void countSort(int arr[],int maxx)
{
    int output[1001];
    int cont[1001], i;

    for(i=0;i<=maxx;++i) cont[i]=0;

    for(i=0;i<n;++i)++cont[arr[i]];

    for(i=1;i<=maxx;++i) cont[i] += cont[i-1];

    for(i=0;i<n;++i)
    {
        output[cont[arr[i]]-1]=arr[i];
        cont[arr[i]]--;
    }

    for(i=0;arr[i];++i) arr[i] = output[i];
}


int main()
{
    int i, maxx;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>arr[i];
        if(i==0) maxx=arr[i];
        else if(arr[i]>maxx) maxx=arr[i];
    }
    countSort(arr,maxx);
    for(i=0;i<n;++i) cout<<arr[i]<<' ';

    return 0;
}
