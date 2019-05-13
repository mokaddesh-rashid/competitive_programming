#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[111];

    cin>>str;

    int i,n,len,x;

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        if('a'==tolower(str[i])||'e'==tolower(str[i])||'i'==tolower(str[i])||'o'==tolower(str[i])||'u'==tolower(str[i])||'y'==tolower(str[i]))
            continue;
        else
        {

                x=str[i];

                if(x<97)
                {
                    str[i]+=32;

                }

                 cout<<'.'<<str[i];
        }
    }
}
