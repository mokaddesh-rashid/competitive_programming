#include<iostream>

using namespace std;

int main()
{
   int i,n,a[99],b,m=0,d;
   cin>>b;
    for(i=0;i<b;i++)
    cin>>a[i];
    d=b;
  for(i=0;i<b;i++,d--)
    for(n=i;n<d;n++)
  {
      if(a[i]>a[n])
        swap(a[i],a[n]);
      if(a[d-1]<a[n])
        swap(a[d-1],a[n]);
  }

   if(b==1)
    cout<<"NO";
   else if(a[0]==a[1])
    {
        while(a[0]==a[m])
        {
            m++;
        }
        cout<<m<<endl;
        if(m==b)
            cout<<"NO";
        else
            cout<<a[m];
    }

    else
        cout<<a[1];

}

