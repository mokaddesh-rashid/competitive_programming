#include<iostream>
#include<string>
#include<cstdio>


using namespace std;

int main()
{
    string str;


    long long int n,a=0,b=0,i,c;

    cin>>n;

    cin>>str;


    for(i=0;i<n;i++)
    {
        if(str[i]=='0')
            a++;

        else
            b++;
    }

    c=min(a,b)*2;

    cout<<n-c;



}
