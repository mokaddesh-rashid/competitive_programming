#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str,command;

    cin>>str;
    cin>>command;

    int i,pos=0;

    for(i=0;i<command.size();i++)
    {
        if(command[i]==str[pos])
           {
               //cout<<"ok";
               pos++;
           }
    }

    cout<<pos+1;

}
