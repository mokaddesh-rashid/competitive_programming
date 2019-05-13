#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int  n,k,l,c,d,p,nl,np;

    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int i,a,b,e,z,x;

    a=(k*l)/nl;
    b=c*d;
    e=p/np;

    x=min(a,b);
    x=min(x,e);
    cout<<x/n;
}
