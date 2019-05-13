#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[111];

    cin>>str;

    int x,i,n,a,b,ar[29]={0},len;

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        x=str[i]-96;
        ar[x]++;
    }

    x=0;

    for(i=0;i<=26;i++)
    {
        if(ar[i]!=0)
            x++;
    }

    if(x%2==0)
        cout<<"CHAT WITH HER!";
    else
       cout<<"IGNORE HIM!";
}
