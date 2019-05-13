#include<iostream>
#include<string>


using namespace std;


int main()
{
    string str;

    int i,x=0,X=0,a,b,c,d,n;
    cin>>n;
    cin>>str;

    n=n/2;

    for(i=0;i<str.size();i++)
    {
        if(str[i]=='x')
            x++;
    }


    cout<<max(n-x,x-n)<<endl;

    for(i=0;i<str.size();i++)
    {
        if(str[i]=='X'&&n>x)
        {
            cout<<'x';
            x++;
        }
        else if(str[i]=='x'&&n<x)
        {
            cout<<'X';
            x--;
        }
        else
            cout<<str[i];

    }

}

