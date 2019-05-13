#include<iostream>

using namespace std;

int main()
{
    long long int num;

    cin>>num;

    int i,n,x=0;

    while(num!=0)
    {
        if(num%10==1)
            num/=10;

        else if(num%100==14)
            num/=100;

        else if(num%1000==144)
           num/=1000;
        else
        {
            x=1;
            break;
        }
    }

  if(x==0)
    cout<<"YES";
  else
   cout<<"NO";
}
