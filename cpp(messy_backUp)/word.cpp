#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[111];

    cin>>str;

    int len,x=0,a,b,c,y=0,i;

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        if(str[i]>='a')
            x++;
        else if(str[i]>='A')
            y++;

    }


    if(y<=x)
    for(i=0;i<len;i++)
        str[i]=tolower(str[i]);

    else
    for(i=0;i<len;i++)
        str[i]=toupper(str[i]);

    cout<<str;






}
