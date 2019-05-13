#include<iostream>
#include<string>

using namespace std;

long long int remove_zero(long long int x)
{
    long long int a,b,c=0;

    while(x>0)
    {
        a=x%10;

        if(a==0)
            x/=10;
        else
        {
            if(c!=0)
               c*=10;

            c=c+a;
            x/=10;

        }

    }

 return c;
}

long long int reverse_num(long long int x)
{
      long long int a,b,c=0;

    while(x>0)
    {
        a=x%10;

        if(a==0)
            x/=10;
        else
        {
            if(c!=0)
               c*=10;

            c=c+a;
            x/=10;

        }

    }

 return c;

}

int main()
{
     long long int a,b,c,x,y,z;

    cin>>a>>b;

    c=a+b;

    x=remove_zero(a);
    x=reverse_num(x);

    y=remove_zero(b);
    y=reverse_num(y);

    z=remove_zero(c);
    z=reverse_num(z);

   if(x+y==z)
    cout<<"YES";

   else
    cout<<"NO";


}
