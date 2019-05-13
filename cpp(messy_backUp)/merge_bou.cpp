#include<iostream>

using namespace std;

void merge_it(int arr[],int st,int mid,int en)
{
    int n,n2;

    n=(mid-st)+1; n2=en-mid;

    int f_half[n+1],s_half[n2+1],i,j,k;

    for(i=0;i<n;i++) f_half[i]=arr[st+i];
    for(i=0;i<n2;i++) s_half[i]=arr[mid+1+i];

    i=j=0; k=st;
    while(i<n&&j<n2)
    {
        if(f_half[i]<s_half[j]) arr[k]=f_half[i],i++,k++;
        else arr[k]=s_half[j],j++,k++;

    }

    while(i<n)
    {
        arr[k]=f_half[i];
        i++; k++;
    }

    while(j<n2)
    {
        arr[k]=s_half[j];
        j++; k++;
    }

}

void divide(int arr[],int st,int en)
{
    int mid;

    if(st<en)
    {
        mid=(st+en)>>1;
        divide(arr,st,mid);
        divide(arr,mid+1,en);

        merge_it(arr,st,mid,en);

    }
}

int main()
{
    int n, ar[10001], i;

    cin>>n;
    for(i=0;i<n;i++) cin>>ar[i];
    divide(ar,0,n-1);
    for(i=0;i<n;i++) cout<<ar[i]<<' ';
}
