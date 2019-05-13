#include<iostream>

using namespace std;

int main()
{
    int a,b,a1,b1,a2,b2,x,y;

    cin>>a>>b>>a1>>b1>>a2>>b2;

   if(a1>b1&&a2>b2)
     swap(a1,b1);

    if(a>=a1+a2&&b>=b1&&b>=b2)
        cout<<"YES";
    else if(b>=a1+a2&&a>=b1&&a>=b2)
        cout<<"YES";
    else if(a>=a1+b2&&b>=b1&&b>=a2)
        cout<<"YES";
    else if(b>=a1+b2&&a>=b1&&a>=a2)
        cout<<"YES";
    else if(a>=a2+b1&&b>=a1&&b>=b2)
        cout<<"YES";
    else if(b>=a2+b1&&a>=a1&&a>=b2)
        cout<<"YES";

    else
        cout<<"NO";
}
