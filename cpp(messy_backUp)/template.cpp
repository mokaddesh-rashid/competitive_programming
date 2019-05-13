#include<iostream>

using namespace std;

template <class hmm>

hmm add(hmm a,hmm b)
{
    return a+b;
}
template <class hmm>
hmm mul(hmm a,hmm b)
{
    return a*b;
}
int main()
{
    int a,b,c;
    float i,n,m;
    double x,y,z;

    cin>>a>>b;
    c=add(a,b);
    cout<<c<<endl;
    cin>>x>>y;
    z=add(x,y);
    cout<<z<<endl;
    cin>>m>>n;
    i=add(n,m);
    cout<<i<<endl;
    cin>>a>>b;
    c=mul(a,b);
    cout<<c<<endl;
    cin>>x>>y;
    z=mul(x,y);
    cout<<z<<endl;
    cin>>m>>n;
    i=mul(n,m);
    cout<<i<<endl;
}
