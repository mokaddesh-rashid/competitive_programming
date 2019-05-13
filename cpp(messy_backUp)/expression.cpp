#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    int a,b,c,x,y;

    cin>>a>>b>>c;

    x=a*b*c;

    y=a+b+c;
     x=max(x,y);

    y=(a+b)*c;
     x=max(x,y);

    y=a*(b+c);
     x=max(x,y);

    y=a+(b*c);
     x=max(x,y);

    y=(a*b)+c;
     x=max(x,y);

     cout<<x;


}
