#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[4];
    int i,n,x=0,a;

    cin>>a;

    for(i=0;i<a;i++)
    {
        cin>>str;

        if(str[0]=='+'||str[1]=='+'||str[2]=='+')
            x++;
        else
            x--;
    }

    cout<<x;
}
