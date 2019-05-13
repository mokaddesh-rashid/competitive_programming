

using namespace std;
#include<iostream>

int facto(int);

int main()
{
    long long int i,n,a[1111],b[111],c,d,e,y,zx;
    cin>>e;
    for(n=e,c=0;n>0;n/=10,c++)
    {
        a[c]=n%10;
    }
    c=c-1;
    d=c;
    for(i=0;i<=c/2;i++,d--)
       {
         e=a[i];
         a[i]=a[d];
         a[d]=e;
       }
    for(i=0;i<=c;i++)
    {
        e=a[i];
        a[i]=facto(e);
        //cout<<a[i]<<endl<<endl;
    }
    d=1;
     for(i=0;i<=c;i++)
    {
        d=a[i]*d;
       // cout<<e;
    }
    e=0;
   for(i=d;i>0;i=i/n)
      for(n=2;n<=i;n++)
    {
        if(i%n==0)
        {
            //cout<<n;
            b[e]=n;
            e++;
            break;
        }

    }
    for(i=0;i<e-1;i++)
        for(n=0;n<e-1;n++)
    {
        if(b[n]<b[n+1])
        {
            y=b[n];
            b[n]=b[n+1];
            b[n+1]=y;
        }
    }
     for(i=0;i<e;i++)
        {
            a[i]=facto(b[i]);
            //cout<<a[i];
        }
    y=1;
    zx=0;
    for(n=0;n<e;n++)
    for(i=0;i<e;i++)
    {
        y=y*a[i];
        if(y==d)
        {
            cout<<b[i];
            zx=1;
            break;
        }
        else if(y<d)
        {
            cout<<b[i];
        }
        else if(y>d)
        {
            y=y/a[i];
        }
        if(zx==1)
            break;
    }


    return 0;



}


int facto(int a)
{
   //cout<<a<<endl;
  if(a==0)
    return 1;
  else
    return a*facto(a-1);
}
