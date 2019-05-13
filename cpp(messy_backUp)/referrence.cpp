#include<iostream>


using namespace std;

void fun(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}


int main()
{
    int a,b;
    cin>>a>>b;
    fun(&a,&b);
    cout<<a<<"\t"<<b;
}
