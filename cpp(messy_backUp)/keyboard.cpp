#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main()
{
    char str[1111],ch;

    cin>>ch>>str;

    int len,i,n,a,b,x;

    len=strlen(str);

    if(ch=='R')
    {
        for(i=0;i<len;i++)
        {
            if(str[i]=='w')
                cout<<'q';
            else if(str[i]=='e')
                cout<<'w';
            else if(str[i]=='r')
                cout<<'e';
            else if(str[i]=='t')
                cout<<'r';
            else if(str[i]=='y')
                cout<<'t';
            else if(str[i]=='u')
                cout<<'y';
            else if(str[i]=='i')
                cout<<'u';
            else if(str[i]=='o')
                cout<<'i';
            else if(str[i]=='p')
                cout<<'o';
            else if(str[i]=='[')
                cout<<'p';
            else if(str[i]=='s')
                cout<<'a';
            else if(str[i]=='d')
                cout<<'s';
            else if(str[i]=='f')
                cout<<'d';
            else if(str[i]=='g')
                cout<<'f';
            else if(str[i]=='h')
                cout<<'g';
            else if(str[i]=='j')
                cout<<'h';
            else if(str[i]=='k')
                cout<<'j';
            else if(str[i]=='l')
                cout<<'k';
            else if(str[i]==';')
                cout<<'l';
            else if(str[i]=='x')
                cout<<'z';
            else if(str[i]=='c')
                cout<<'x';
            else if(str[i]=='v')
                cout<<'c';
            else if(str[i]=='b')
                cout<<'v';
            else if(str[i]=='n')
                cout<<'b';
            else if(str[i]=='m')
                cout<<'n';
            else if(str[i]==',')
                cout<<'m';
            else if(str[i]=='/')
                cout<<'.';
             else if(str[i]==']')
                cout<<'[';
            }
    }

     if(ch=='L')
    {
        for(i=0;i<len;i++)
        {
            if(str[i]=='    ')
                cout<<'q';
            else if(str[i]=='q')
                cout<<'w';
            else if(str[i]=='w')
                cout<<'e';
            else if(str[i]=='e')
                cout<<'r';
            else if(str[i]=='r')
                cout<<'t';
            else if(str[i]=='t')
                cout<<'y';
            else if(str[i]=='y')
                cout<<'u';
            else if(str[i]=='u')
                cout<<'i';
            else if(str[i]=='i')
                cout<<'o';
            else if(str[i]=='o')
                cout<<'p';
            else if(str[i]=='a')
                cout<<'s';
            else if(str[i]=='')
                cout<<'s';
            else if(str[i]=='s')
                cout<<'d';
            else if(str[i]=='d')
                cout<<'f';
            else if(str[i]=='f')
                cout<<'g';
            else if(str[i]=='g')
                cout<<'h';
            else if(str[i]=='h')
                cout<<'j';
            else if(str[i]=='j')
                cout<<'k';
            else if(str[i]=='k')
                cout<<'l';
            else if(str[i]=='')
                cout<<'z';
            else if(str[i]=='z')
                cout<<'x';
            else if(str[i]=='x')
                cout<<'c';
            else if(str[i]=='c')
                cout<<'v';
            else if(str[i]=='v')
                cout<<'b';
            else if(str[i]=='b')
                cout<<'n';
            else if(str[i]=='n')
                cout<<'m';
             else if(str[i]=='m')
                cout<<',';
            else if(str[i]==',')
                cout<<'.';
        }
    }



}
