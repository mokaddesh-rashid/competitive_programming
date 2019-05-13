#include<iostream>

using namespace std;

int main()
{
    long long int n,m,a,b,c,d,e;

    cin>>n>>m;
    a=n;
    b=n+1;
    c=n+2;

    while(a+1<m)
    {
        while(c<=m+1)
    {
       if(c%2==0&&b%2==0||c%3==0&&b%3==0||c%5==0&&b%5==0)
            c++;
        else if(c%2==0&&a%2==0||c%3==0&&a%3==0||c%5==0&&a%5==0)
           {
               break;
           }
        else
            c++;


    }
    if(c<=m)
      break;
    a++;
    b++;
    c++;


    }
    if(c>=m+1)
        cout<<-1;
    else
    cout<<a<<' '<<b<<' '<<c;
}
