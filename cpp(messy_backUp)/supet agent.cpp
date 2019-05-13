
#include<iostream>

using namespace std;

int main()
{
    char str[10],ch;
    int a=8,b,i=0,n;

    while(cin>>ch)
    {
        str[i]=ch;
        i++;
    }
    for(i=0;i<9;i++,a--)
    {
         if(str[i]==str[a]&&i==8)
        {
            cout<<"YES";
        }
       else if(str[i]==str[a])
            continue;
        else
        {
             cout<<"NO";
             break;
        }
    }
}
