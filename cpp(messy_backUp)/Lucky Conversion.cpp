#include<iostream>
#include<string>

using namespace std;


int main()
{
    string str,st;

    cin>>str;
    cin>>st;

    long long int i,j,f=0,s=0,x,y;


    for(i=0;i<str.size();i++)
    {
        if(str[i]!=st[i])
        {
            if(str[i]=='7')
                s++;
            else
                f++;
        }
    }


    cout<<max(s,f);
}
