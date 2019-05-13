#include<iostream>

using namespace std;

int main()
{
    int n,m,i,a=1,b,c,x=1;

    cin>>n>>m;


    x=m;
    if(n<m)
        cout<<-1;
    else if(n==m||m==1)
        cout<<n;

    else
    {
       if(n%2)
        n++;

       while(x<n/2)
       {
           x=m*a;
           a++;
       }

       cout<<x;
    }
}
