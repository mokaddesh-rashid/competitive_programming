#include<iostream>

using namespace std;

int main()
{
    int n,i,x=0,a,b=0,c=0;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a;

        if(a==-1&&b==0)
            x++;
        else(a==-1&&b>0)
            b--;
        else
            b+=a;
    }
    cout<<x;
}
