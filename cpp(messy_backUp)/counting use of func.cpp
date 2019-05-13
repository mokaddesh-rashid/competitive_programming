#include<iostream>

using namespace std;

void func( int *);

int main()
{
    int a=0,b,c;
    func(&a);
    func(&a);
    cout<<a;


}
void func(int *p)
{
    //int p=0;
    *p=*p+1;
    //int x;

}


