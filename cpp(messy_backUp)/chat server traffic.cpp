#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    int a=0,b=0,d;
    char ch[111],c;
    while(cin.get(c))
    {
        if(c=='+')
        {
            a++;

        }
        else if(c=='-')
            a--;
        else if(c==':')
        {
            gets(ch);
            b=strlen(ch);
            d=d+(b*a);
        }
    }
    cout<<d;
}
