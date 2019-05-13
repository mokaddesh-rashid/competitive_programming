#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int ar[n+1],i,x=0,a,b;

    for(i=0;i<n;i++)
        cin>>ar[i];

    for(i=0;i<n;i++)
    {
        a=ar[i];

        while(a==ar[i])
        {
            if(a==ar[i])
                 i++;
        }
        i--;
        //cout<<i<<endl<<x<<endl<<endl;
        x++;
    }

    cout<<x;
}
