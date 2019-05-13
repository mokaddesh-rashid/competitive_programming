#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,n,m,x,y;
    cin>>a>>b>>n>>m;
    if(a<n)
    {
        swap(a,n);
        swap(b,m);
    }
    x=n-a;
    y=max(m,b)-(min(m,b)+x);
    cout<<x+y;

}

