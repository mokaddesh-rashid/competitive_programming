#include<iostream>

using namespace std;

int swp[100], arr[100];

int main()
{
    int i, k, j, n, cnt=0, a, b, c;

    cin>>n;
    for(i=0;i<n;i++) cin>>arr[i];

    for(i=1;i<n;i++)
    {
        k=arr[i];
        j=i-1;
        c=0;
        while(j>=0&&arr[j]<k)
        {
            arr[j+1]=arr[j];
            c++;
            j--;
        }
        swp[i]=c;
        cnt+=c;
        arr[j+1] = k;

    }

    cout<<"Sorted in descending order = ";
    for(i=0;i<n;i++) cout<<arr[i]<<' ';
    cout<<endl;

    cout<<"total count of swap "<<cnt<<endl;
    for(i=0;i<n;i++)
    {
        cout<<swp[i]<<' ';
    }


    return 0;
}
