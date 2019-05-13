#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int x=0,i,b=1,c=0,a,d=1;


    for(i=0;i<n;i++)
    {
        cin>>b;
        x+=b;
    }

   a=n+1;


  while(x+5>=d)
  {
      if(d%a!=1&&d>x)
        c++;
        //cout<<d<<' ';
      d++;
  }
 // cout<<d<<endl;
  cout<<c;

}
