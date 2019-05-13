
#include<iostream>

using namespace std;

int main()
{
    int a,b,t,x,i,n,c;

    cin>>a>>b>>c;

    for(i=0;i>=0;i++)
    {
        n=1;
        if(c==0)
            x=a;
        else
        while(n<=a&&n<=c)
        {
            if(a%n==0&&c%n==0)
                x=n;
            n++;
        }
        if(x>c)
        {
            cout<<"1";
            break;
        }

        else
            c-=x;
        n=1;
        if(c==0)
            x=b;
        else
        while(n<=b&&n<=c)
        {
            if(b%n==0&&c%n==0)
                x=n;
            n++;
        }
        if(x>c)
        {
            cout<<"0";
            break;
        }

        else
            c-=x;
    }
}
