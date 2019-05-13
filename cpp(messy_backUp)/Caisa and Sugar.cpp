#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,s;

    cin>>n>>s;

    int x,i,a,b,c,d,y,maxi=0,m;

    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        a=(s*100)/(x*100+y);
        b=x*100+y;

        for(m=1;m<=a;m++)
        {
            c=b*m;
            c=c%100;
            maxi=max(c,maxi);
        }
    }
    cout<<maxi;
}
