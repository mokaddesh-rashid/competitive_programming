#include<iostream>

using namespace std;

int main()
{
    long long int n,m,a,c,d;
    cin>>n>>m>>a;
    if(n%a)
       c=n/a+1;
    else
        c=n/a;
    if(m%a)
       d=m/a+1;
    else
        d=m/a;
    cout<<c*d;
}
