#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{

    int n,V,por[1111],ans=0,x=0,value[1111],i;

    cin>>n>>V;

    for(i=0;i<n;i++)
        cin>>por[i];
    for(i=0;i<n;i++)
       {
           cin>>value[i];
           if(x>value[i]&&por[i]==1)
            x=value[i];
       }

    for(i=0;i<n;i++)
    {
        ans=ans+(x*por[i]);
    }

    cout<<ans;

}
