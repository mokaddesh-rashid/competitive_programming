#include<iostream>

using namespace std;

int main()
{
    double n,i,x=0,a,b;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a;

        x=x+a;
    }

    cout<<x/n;


}
