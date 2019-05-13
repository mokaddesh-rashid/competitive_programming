#include<iostream>
#include<string>
#include<cstring>


using namespace std;

int main()
{
    string str;

    cin>>str;

    int pos;

    pos=str.find("WUB");

    while(pos!=string::npos)
    {
        str.replace(pos,3," ");
         pos=str.find("WUB");


    }

     pos=str.find("  ");

    while(pos!=string::npos)
    {
        str.replace(pos,2," ");
         pos=str.find("  ");


    }


    int x=0,i;

    pos=str.length();

    for(i=0;i<pos;i++)
    {

        if(x==0&&str[i]==' ')
        {
           continue;
        }

        else
        {
            x=1;
            cout<<str[i];
        }
    }
}
