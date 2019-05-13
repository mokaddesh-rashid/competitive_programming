#include<iostream>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    int arr[111]={0},a,b,c,d;

    while(m>0)
    {
        int x;
        cin>>x;

        for(int i=x;i<=n;i++)
        {
            if(arr[i]==0)
                arr[i]=x;
        }
        m--;
    }

    for(int i=1;i<=n;i++)
        cout<<arr[i]<<' ';
}
