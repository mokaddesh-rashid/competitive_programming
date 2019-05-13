#include<iostream>

using namespace  std;

int main()
{
    long long int k,l;

    cin>>k>>l;

    long long int i,a,b,c,x,y=0;

    x=k;

    while(k<l)
    {
        k=k*x;
        y++;

    }

    if(k==l)
        cout<<"YES"<<endl<<y;
    else
        cout<<"NO";


}
