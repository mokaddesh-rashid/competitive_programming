#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    if(n==1||n==2)
        cout<<-1;

    else
    {
        while(n>0)
        {
            cout<<n+2<<' ';
            n--;
        }
    }
}
