#include<iostream>

using namespace std;

class A
{
    public:
    int a,b,c,i,d;
    int area(int a,int b)
    {
        return a*b;
    }
    int square(int z)
    {
        return z*z;
    }
    void print(int k)
    {
        cout<<k;
    }

};

int main()
{
    A hm;
    cin>>hm.a>>hm.b;
    hm.c=hm.area(hm.a,hm.b);
    hm.d=hm.square(hm.c);
    hm.print(hm.d);
    return 0;


}
