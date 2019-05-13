#include<iostream>

using namespace std;

int main()
{
    int i,n,p1,p2,p3,t1,t2,x=0,y=0,ar[111][111],a,b,c,m,d=0;
    cin>>n>>p1>>p2>>p3>>t1>>t2;

    for(m=0;m<n;m++)
    {
        cin>>a>>b;
        c=b-a;
        y=y+(c*p1);
       if(m!=0)
        for(i=0;i<a-d;i++)
        {

            if(i<t1)
               { y=y+p1;

               }

            else if(i>=t1&&i<t1+t2)
               {
               	y=y+p2;
               }

            else if(i>=t2+t1)
              {
              	y=y+p3;
              }
        }
        d=b;
    }
    cout<<y;
}
