#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;

    cin>>str;

    int x=0,i,a,b,c;

    x=0;

    while(str[x]!='0'&&x<str.size())
    {
        //cout<<x<<endl;
        x++;
    }

    if(x==str.size())
       x--;


    for(i=0;i<str.size();i++)
    {
        if(i==x)
            continue;
        else
            cout<<str[i];
    }
}
