#include<iostream>

using namespace std;

int main()
{
    char str[9][9];
    int i,n,a=1,b=0;


    for(i=0;i<8;i++)
    {
        cin>>str[i];
        if(strcmp(str[i],"BBBBBBBB")==0)
            b++;
    }
    for(i=0;i<8;i++)
        for(n=0;n<8;n++)
    {
        if(str[n][i]=='B')
            a++;
        if(a==8)
            b++;
        if(a==7)
            a=0;
    }
    cout<<b;
}
