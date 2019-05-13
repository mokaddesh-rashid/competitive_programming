#include <iostream>

using namespace std;

void mergee(int arr[],int index[],int start,int mid,int endd)
{
    int n1,n2,i,j,k;

    n1=mid-start+1;
    n2=endd-mid;

    int f_part[n1+1],s_part[n2+1],f_index[n1+1],s_index[n2+1];

    for(int i=0;i<n1;i++)
       {
          f_part[i]=arr[start+i];
          f_index[i]=index[start+i];
       }

    for(int i=0;i<n2;i++)
       {
          s_part[i]=arr[mid+1+i];
          s_index[i]=index[mid+1+i];
       }

    i=0;
    j=0;
    k=start;

    while(i<n1&&j<n2)
    {
        if(f_part[i]<s_part[j])
        {
            arr[k]=f_part[i];
            index[k]=f_index[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=s_part[j];
            index[k]=s_index[j];
            k++;
            j++;
        }
    }

    while(i<n1)
    {
            arr[k]=f_part[i];
            index[k]=f_index[i];
            i++;
            k++;
    }

    while(j<n2)
    {
            arr[k]=s_part[j];
            index[k]=s_index[j];
            k++;
            j++;
    }
}

void divide(int arr[],int index[],int start,int endd)
{
    if(start<endd)
    {
        int mid=(start+endd)/2;

        divide(arr,index,start,mid);
        divide(arr,index,mid+1,endd);

        mergee(arr,index,start,mid,endd);

    }
}



int main()
{
    int n,i,k,a;

    cin>>n>>k;

    int  arr[n+1],index[n+1];

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        index[i]=i;
    }

    divide(arr,index,0,n-1);

    for(i=0;i<n;i++)
    {
        a=arr[i];
        b=arr[i]*k;
    }

}
