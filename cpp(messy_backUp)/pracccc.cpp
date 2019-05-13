#include<iostream>

using namespace std;

class A
{
    public:
    int i,n=2,a,b;
    A(int x)
    {
        for(n=2;n<x;n++)
        {
            if(x%n==0)
            {
                i=0;
                break;
            }
            else i=1;
        }

       }
         void prnt(int x)
        {
            if(x==0)cout<<"not a primenumber";
            else if(x==1) cout<<" a primenumber";
        }
};
int main()
{
    int x;
    cin>>x;
  A ob(x);


  ob.prnt(ob.i);
  return 0;


}


