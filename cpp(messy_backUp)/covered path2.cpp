#include<iostream>

using namespace std;

int main()
{
    int u,v,t,d;

    cin>>u>>v>>t>>d;


    int x=0,a=0,b=0,c=0;

    while(v-u<(t-1)*d&&t>0)
    {
        //cout<<v<<' ';
        x+=v;
        v+=d;
        t--;
    }

    while(u-v<t*d&&t>0)
    {
        //cout<<u<<' ';
        x+=u;
        u+=d;
        t--;
    }

    if(d==0)
        cout<<u*t;
    else
      cout<<x;

}
