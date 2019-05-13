#include<iostream>

using namespace std;

int main()
{
    long long int n,m;

    cin>>n>>m;

    long long int a=0,b=0,x=0;

    while(x<=m)
    {
      if(n%m==0)
      {
          b=1;
          break;
      }

      else
      {
          n=n+(n%m);
      }
      x++;
    }


    if(b==0)
        cout<<"No";
    else
        cout<<"Yes";
}
