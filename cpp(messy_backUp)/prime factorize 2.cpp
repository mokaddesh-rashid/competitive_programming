#include<iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t,n,a,x=0,i,b,m;

    cin>>t;

    for(i=0;i<t;i++)
    {
        cin>>a;

        for(n=a;n>0;n/=m)
            for(m=2;m<=n;m++)
        {
            if(n%m==0)
            {
                x+=m;
                break;
            }
        }
    }

    cout<<x;
}
