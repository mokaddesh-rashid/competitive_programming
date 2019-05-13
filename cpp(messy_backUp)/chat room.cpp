#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[111];

    cin>>str;

    int len,i,n,a,b,x,h=0,e=0,l=0,o=0;

    len=strlen(str);

    for(i=0;i<len;i++)
    {
        if(str[i]=='h'&&h==0)
        {
           h=1;
           cout<<'h';
        }
        else if(str[i]=='h'&&h==1)
            continue;
        else if(str[i]=='e'&&h==1&&e==0)
        {
           e=1;
            cout<<'e';
        }
        else if(str[i]=='e'&&e==1)
            continue;
        else if(str[i]=='l'&&e==1&&l<2)
        {
           l++;
            cout<<'l';
        }
        else if(str[i]=='l'&&l>2)
            continue;

         else if(str[i]=='o'&&l==2)
        {
            cout<<'YES';
           o=1;
           break;
        }

    }

    if(e==0)
        cout<<"NO";
}
