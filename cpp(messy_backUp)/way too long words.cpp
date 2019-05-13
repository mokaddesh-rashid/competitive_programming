#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,len,i,x;

    cin>>n;

    char str[1111];

    for(i=0;i<n;i++)
    {
        cin>>str;

        len=strlen(str);

        if(len<=10)
            cout<<str<<endl;

        else
            cout<<str[0]<<len-2<<str[len-1]<<endl;
    }
}


