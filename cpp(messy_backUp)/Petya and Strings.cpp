#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char P[111],T[111];

    cin>>P>>T;

    int len,i,n,a,x;

    len=strlen(P);

    for(i=0;i<len;i++)
    {
        x=P[i];

        if(x<97)
            P[i]+=32;
    }
    for(i=0;i<len;i++)
    {
        x=T[i];

        if(x<97)
            T[i]+=32;
    }

    cout<<strcmp(T,P);
}
