#include <iostream>

using namespace std;

class a
{
public:
    int i,z,n;
    a(int x,int y)
    {
        i=x;
        n=y;

    }

   int math(int x,int y)
    {
        return x+y;
    }
   int math(int x)
    {
        return x*x;
    }
   void math (int *x)
   {
       cout<<*x;
   }
};

int main()
{

    a od(7,7);
    od.z=od.math(od.i,od.n);
    od.z=od.math(od.z);
    od.math(&od.z);
return 0;

}
