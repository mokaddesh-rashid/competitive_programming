#include<iostream>

using namespace std;

int main()
{
    int x=0,n,i,a,b;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a>>b;

        if(b-a>=2)
            x++;
    }

    cout<<x;
}
