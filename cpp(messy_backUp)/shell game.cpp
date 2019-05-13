#include<iostream>

using namespace std;

int main()
{
    int ar[44],a,b,c,i,n,x;

    for(i=0;i<3;i++)
    {
        ar[i]=0;
    }

    cin>>a;

    ar[a-1]=1;

    for(i=0;i<3;i++)
    {
        cin>>a>>b;

        swap(ar[a-1],ar[b-1]);
    }

    for(i=0;i<3;i++)
    {
        if(ar[i]==1)
        {
            cout<<i+1;
        }
    }
}
