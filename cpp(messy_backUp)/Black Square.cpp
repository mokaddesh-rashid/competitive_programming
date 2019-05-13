#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;

    long long int x,y,n,a=0,b,level[6]={0},i;

    for(i=1;i<5;i++)
        cin>>level[i];

    cin>>str;

    for(i=0;i<str.length();i++)
    {
        x=str[i]-48;
        //cout<<x<<endl;
        a=a+level[x];
    }

      cout<<a;
}
