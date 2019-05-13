#include<iostream>
#include<string>


using namespace std;

int main()
{
    long long int n;

    cin>>n;

    string str;

    cin>>str;

    long long int a=0,f=0,i0=0,i,j;

    for(i=0;i<str.size();i++)
    {
        if(str[i]=='I')
            i0++;
        else if(str[i]=='A')
            a++;
    }

    if(i0>1)
        cout<<0;
    else if(i0==1)
        cout<<1;
    else
        cout<<a;
}
