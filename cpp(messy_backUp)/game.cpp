#include<iostream>

using namespace std;

int main()
{
    int n1,n2,k1,k2;

    cin>>n1>>n2>>k1>>k2;

    if(n1==n2||n1<n2)
        cout<<"Second";

    else if(n1>n2)
        cout<<"First";

}
