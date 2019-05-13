#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string str,ss;
    char a,b,c,d;

    cin>>str;
    cin>>ss;

    int i,j,x=0;


    if(str.size()==ss.size())
    for(i=0;i<str.size();i++)
    {
        if(str[i]!=ss[i])
        {
            x++;
            if(x==1)
            {
              a=str[i];
              b=ss[i];
            }
            else
            {
                 c=str[i];
                 d=ss[i];
            }
        }
    }
    //cout<<x<<' '<<a<<' '<<d<<' '<<b<<' '<<c<<endl;

    if(str.size()==ss.size()&&x==2&&a==d&&b==c)
        cout<<"YES";
    else
        cout<<"NO";

}

