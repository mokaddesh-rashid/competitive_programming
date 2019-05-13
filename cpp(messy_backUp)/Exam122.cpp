#include<iostream>


using namespace std;

int main()
{
    int n,k,a,b;

    cin>>n>>k;

    a=k-(2*n);


    if(a>=n)
        cout<<0;
    else
        cout<<n-a;
}
