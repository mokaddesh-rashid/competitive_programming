#include<iostream>

using namespace std;

int main()
{
    int n,x=0;

    cin>>n;

    for(i=0;i<n;i++)
    {
        int a,b,c;

        cin>>a>>b>>c;

        if(a+b+c>1)
            x++;
    }

    cout<<x;
}
