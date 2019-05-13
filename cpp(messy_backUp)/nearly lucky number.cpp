#include<iostream>

using namespace std;

int main()
{
    long long int n,i,x=0,a,b;

    cin>>n;

    while(n>0)
    {
        a=n%10;
        n/=10;
        if(a==7||a==4)
            x++;

    }

    //cout<<x;

    if(x==7||x==4)
        cout<<"YES";

    else
        cout<<"NO";
}
