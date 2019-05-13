#include<iostream>

using namespace std;

int main()
{
    int i,n,a,b,c,x=0,y;

    cin>>a>>b>>c;

    x=a+b+c;

    if(x%5!=0)
        x++;
     x=x+(x/5);

    y=a+b+c;

    if(y%10!=0)
        y++;
     y=y+(y/10);

    x=x+y;

    cin>>a;

    if(a>=x)
        cout<<"YES";

    else
        cout<<"NO";
}
