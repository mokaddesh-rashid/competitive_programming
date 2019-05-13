#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;

    cin>>str;

    int a,b,c;

    if(str[0]=='0')
        a=2;
    else if(str[0]=='1')
        a=7;
    else if(str[0]=='2')
        a=2;
     else if(str[0]=='3')
        a=3;
     else if(str[0]=='4')
        a=3;
     else if(str[0]=='5')
        a=4;
     else if(str[0]=='6')
        a=2;
     else if(str[0]=='7')
        a=5;
     else if(str[0]=='8')
        a=1;
     else if(str[0]=='9')
        a=2;

     if(str[1]=='0')
       b=2;
    else if(str[1]=='1')
       b=7;
    else if(str[1]=='2')
       b=2;
     else if(str[1]=='3')
       b=3;
     else if(str[1]=='4')
       b=3;
     else if(str[1]=='5')
       b=4;
     else if(str[1]=='6')
       b=2;
     else if(str[1]=='7')
       b=5;
     else if(str[1]=='8')
       b=1;
     else if(str[1]=='9')
       b=2;

       cout<<a*b;
}
