#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int home[n+1],away[n+1],i,x=0,a,m;

    for(i=0;i<n;i++)
        cin>>home[i]>>away[i];

    for(i=0;i<n;i++)
        for(m=0;m<n;m++)
    {
        if(i==m)
            continue;

        else if(home[i]==away[m])
            x++;
    }

    cout<<x;
}
