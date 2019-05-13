#include<iostream>

using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    long long int n;

    cin>>n;

    long long int ne[n+2],pi[n+2],x=1111,i,j,a=0,b,c,m=0,d,k,p;

    for(i=0;i<n;i++)
    {
        cin>>k>>p;

        if(i==0)
        {
            x=p;

            a=a+(k*x);
        }

        else
        {
            x=min(x,p);
            a=a+(k*x);
        }
    }

    cout<<a;
}
