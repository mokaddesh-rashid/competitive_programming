
#include<iostream>
#include<string.h>

using namespace std;

class test
{

public:
    int i,n,a,b,c;
    static int x;
    test(int z)
    {
        a=z;
    }
    void func()
    {
        cout<<"value of a="<<a<<"\n";
        x++;

    }
};
int test::x;

int main()
{
    int a,i;
   cin>>a;
   test ob(a);
   for(i=0;i<a;i++)
   {
     ob.func();
   }


   cout<<ob.x;

}
