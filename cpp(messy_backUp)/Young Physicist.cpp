#include<iostream>

using namespace std;

int main()
{
    int n,a,b,c,x=0,i;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;

        x+=a;
        x+=b;
        x+c;
    }

    cout<<x;
}
