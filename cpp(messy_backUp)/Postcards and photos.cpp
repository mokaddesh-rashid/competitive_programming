#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    char ch;

    cin>>str;


    int i,x=0,a=0,b,c;


    for(i=0;i<str.size();i++)
    {
        if(i==0)
        {
            ch=str[i];
            x++;
            a=1;
        }
        else if(str[i]!=ch||a==5)
        {
            ch=str[i];
            x++;
            a=1;

        }
        else
            a++;
    }

    cout<<x;
}
