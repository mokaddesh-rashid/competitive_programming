#include<iostream>

using namespace std;

int main()
{
    int t,c;

    cin>>t;

    for(c=0;c<t;c++)
    {
        int D,d,i,n,z=0,x=0;
    cin>>D;


    int P[D+1];
    d=D;

    for(i=0;i<D;i++)
        cin>>P[i];

    for(i=0;i<2;i++)
    for(n=i;n<d;n++)
    {
        if(P[i]<P[n])
            swap(P[i],P[n]);
    }
    if(D==1)
    {
         x=P[0];
      while(x!=0)
      {
          if(x%2==0)
          {
              x/=2;
              z++;
          }
          else
          {
            x-=1;
            z++;
          }
      }

    }
    else if(P[0]==P[1])
        z=P[0];

    else
    {
        z=P[1];
        P[0]=P[0]-P[1];
        x=P[0];
      while(x!=0)
      {
          if(x%2==0)
          {
              x/=2;
              z++;
          }
          else
          {
            x-=1;
            z++;
          }
      }
    }
    // Case #1: 3
    cout<<"Case"<<' '<<"#"<<c+1<<':'<<' '<<z<<endl;
    }
}
