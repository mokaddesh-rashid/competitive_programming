#include<iostream>

using namespace std;

int main()
{
    int i,n,m,c=0,b;
    cin>>n>>m;
    while(n<m)
    {
        if(m%2)
        {
            m=m+1;
            c++;
        }
        else
        {
            m=m/2;
            c++;
        }
    }
    cout<<c+(n-m);
}
