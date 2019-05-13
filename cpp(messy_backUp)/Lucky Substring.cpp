#include<iostream>
#include<string>


using namespace std;


int main()
{
    string str;

    cin>>str;

    int a=0,b=0;


    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='4')
            a++;
        else if(str[i]=='7')
            b++;
    }

    if(a==0&&b==0)
        cout<<"-1";
    else if(a>=b)
       cout<<4;
    else
        cout<<7;
}
