#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,m,a,b,x,y;

    cin>>n>>m>>a>>b;

    x=n*a;

    y=(n/m);
    if(n%m)
        y++;
    y=y*b;

    x=min(x,y);

    y=(n/m)*b;

    y=y+((n%m)*a);

    x=min(x,y);

    cout<<x;
}
