#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[111];

    cin>>str;

    int len,i,x,a,b,c,d=0,n;

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        x=0;
        n=i;

        while(str[n]==str[i])
        {
            n++;
            x++;
        }

        if(x>=7)
            d=1;
    }

    if(d==1)
        cout<<"YES";

    else
        cout<<"NO";


}
