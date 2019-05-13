#include<iostream>

using namespace std;

int main()
{
    int n,m;

    cin>>n;

    int arr[n+1],i,x,a,b,c;

    for(i=0;i<n;i++)
        cin>>arr[i];

    cin>>m;

    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        a--;

        if(a!=0)
         arr[a-1]+=(b-1);

        if(a!=n-1)
            arr[a+1]=arr[a+1]+(arr[a]-b);
        arr[a]=0;
    }
     for(i=0;i<n;i++)
        cout<<arr[i]<<endl;
}
