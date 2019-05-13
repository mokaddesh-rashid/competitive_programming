#include<iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n,m;

    cin>>n>>m;

    long long int a=0,b=0,c,d,e,f,h=0,x,y,z,chk=0;


    while(m>0)
    {
        cin>>c>>d;
        h=max(h,d);

        x=c-a;

        z=max(d-b,b-d);
        //cout<<x<<' '<<z<<endl;
        if(x<z&&a!=0)
            chk=1;

        //cout<<d<<' '<<b<<endl;

        while(x>0&&b-d<x-1)
        {

           if(b<=d||b-d<x-1)
              b++;
            x--;
            h=max(h,b);
            //cout<<b<<' ';
        }
        a=c;
        b=d;
        m--;
       // cout<<endl<<endl;

    }
   // if()
     h=max(h,(n-c)+d);

    if(chk==1)
       cout<<"IMPOSSIBLE";

    else
       cout<<h;


}
