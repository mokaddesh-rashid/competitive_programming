#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[55];

    cin>>str;

    int len,i,n,a,v,x=0;

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        if(str[i]=='H'||str[i]=='Q'||str[i]=='9'||str[i]=='+')
            x=1;
    }
    if(x==1)
        cout<<"YES";

    else
        cout<<"NO";

}
