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

    string str;

    int n;

    cin >> n;

    cin >> str;

    int i, j, a=0, b=0, c=0, d, s, t;

    for( i=0; i<str.size(); i++)
    {
        if(a==0&&str[i]!='.')
        {
           s = i+1;
           t = i+1;
           a++;
        }

        else if(c==0 && str[i] != '.')
        {
            t = i+1;
        }
        if(str[i]=='R'&&str[i+1]=='L')
        {
            t = i+1;
            c++;
            break;
        }
    }
    if(c==0&&str[t-1]=='R')
       cout<<s<<' '<<t+1;
    else if(c==0&&str[t-1]=='L')
       cout<<t<<' '<<s-1;
     else
    cout << s <<' '<< t;




}

