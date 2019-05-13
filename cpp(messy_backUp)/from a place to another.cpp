#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,n,m,x,y;
    cin>>a>>b>>n>>m;
    if(a>n)
    {
        swap(a,n);
        swap(b,m);
    }
    x=n-a;
    if(x>= max(m-b,b-m))
        cout<<x;
    else if(m+n<b)
        cout<<b-m;
    else
       {

            cout<<x+(m-(x+b));
       }
}
