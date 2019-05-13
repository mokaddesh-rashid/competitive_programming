#include<iostream>

using namespace std;

int main()
{
    long long int n,m,c1,c2,c3,c4;

    cin>>c1>>c2>>c3>>c4;

    cin>>n>>m;


    long long int x=0,y,i,j,a,b,c,x2=0;


    for(i=0;i<n;i++)
    {
        cin>>a;

        y=min(a*c1,c2);

        x+=y;

    }

    x=min(x,c3);

    for(i=0;i<m;i++)
    {
        cin>>a;

        y=min(a*c1,c2);

        x2+=y;

    }

    x2=min(x2,c3);

    x=min(x+x2,c4);


    cout<<x;






}
