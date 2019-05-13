#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int a=n-10;

    if(a==1||a==11||a==2||a==3||a==4||a==5||a==6||a==7||a==9||a==8)
        cout<<4;
    else if(a==10)
        cout<<15;
    else
        cout<<0;
}
