#include<iostream>

using namespace std;

void fun(int *a,int n)
{
    int i;
    for(i=0;i<3;i++)
    cout<<a[i]<<endl;
}
int main()
{
    int i,n=3,a[22];
    for(i=0;i<3;i++)
    cin>>a[i];
    fun(a,n);
    return 0;



}
