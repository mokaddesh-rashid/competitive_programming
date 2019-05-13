#include<iostream>
#include<math.h>
#include<cstdio>

using namespace std;

int main()
{
    int n,x=0,i=1,a;

    cin>>n;

    while(i!=n)
    {
        a=(n-i)*i;
        x+=a;
        i++;

    }

    cout<<x+n;


}
