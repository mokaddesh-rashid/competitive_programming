#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    char str[111],st[111];
    int n,x=0,y=0,i;

    cin>>n;

    for(i=0;i<n;i++)
    {
        char s[111];

        cin>>s;

        if(i==0)
        {
            strcpy(str,s);
            x++;
        }

        else if(strcmp(str,s)==0)
        {
            x++;
        }
        else if(strlen(st)==0)
        {
            strcpy(st,s);
            y++;

        }
        else if(strcmp(st,s)==0)
        {
            y++;
        }
    }

    if(x>y)
        cout<<str;

    else
        cout<<st;
}
