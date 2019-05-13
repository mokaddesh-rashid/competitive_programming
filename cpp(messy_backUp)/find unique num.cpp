
#include<iostream>

using namespace std;

int main()
{
    int ar[101],n,i,a,x,b;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        if(ar[i]%2==0)
            x++;
        else
            y++;

    }

    if(x>y)
        x=1;
    else
        x=0;

    for(i=0;i<n;i++)
    {
        if(ar[i]%2==x)
        {
            cout<<ar[i];
        }
    }


}
