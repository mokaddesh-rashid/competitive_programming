#include<iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;

    while(a>=1)
    {
        cout<<a%2<<' ';
        a/=2;
    }
}
