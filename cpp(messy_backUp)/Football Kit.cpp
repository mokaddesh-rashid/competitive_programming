#include<iostream>

using namespace std;

int main()
{
    long long int home[10*10*10*10*10+2]={0},n,m;

    cin>>n;

    m=(n-1)*2;

    long long int away[n+1],i,a,b,c,x;

    for(i=0;i<n;i++)
    {
        cin>>a>>away[i];

       home[a]++;
    }

    for(i=0;i<n;i++)
    {
        x=away[i];

        if(home[x]==0)
            cout<<n-1<<' '<<n-1<<endl;

        else
           cout<<(n-1)+home[x]<<' '<<n-1-home[x]<<endl;

    }
}
