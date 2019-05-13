#include<iostream>

using namespace std;

int main()
{
    int x;

    cin>>x;
    x++;

    int i,n,a=0,b,c,d;

    b=x*2;
    b-=2;


    for(i=0;i<x;i++,b-=2)
    {
        a=b;
        while(a!=0)
        {
            cout<<' ';
            a--;
        }
        a=0;
        while(a<=i)
        {
            if(a==0&&i==0)
                cout<<0;
            else
            cout<<a<<' ';
            a++;
        }
        a-=2;
        while(a>=0)
        {
            if(a==0)
                cout<<0;
            else
            cout<<a<<' ';
            a--;
        }
        cout<<endl;
    }

    b=2;
    for(i=x-2;i>=0;i--,b+=2)
    {
        a=b;
        while(a!=0)
        {
            cout<<' ';
            a--;
        }
        a=0;
        while(a<=i)
        {
            if(a==0&&i==0)
                cout<<0;
            else
            cout<<a<<' ';
            a++;
        }
        a-=2;
        while(a>=0)
        {
            if(a==0)
                cout<<0;
            else
            cout<<a<<' ';
            a--;
        }
        cout<<endl;
    }
}
