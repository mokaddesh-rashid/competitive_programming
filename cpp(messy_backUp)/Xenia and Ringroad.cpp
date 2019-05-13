#include<iostream>

using namespace std;

int main()
{
    long long int n,m,x=1,a,b,z;

    cin>>n>>m;

    long long int house[m+1],i,y=0;

    for(i=0;i<m;i++)
    {
        cin>>house[i];

        if(house[i]>x)
        {
              y=y+(house[i]-x);
              x=house[i];
        }
        else if(x>house[i])
        {
            z=n-x;
            z+=house[i];
            y+=z;
            x=house[i];
        }
    }

   cout<<y;
}
