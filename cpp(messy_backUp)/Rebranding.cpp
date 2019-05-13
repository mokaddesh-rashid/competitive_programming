#include<iostream>
#include<string>

using namespace std;

int main()
{

    int n,m;


    cin>>m>>n;
    string str,stt,ss;

    stt="abcdefghijklmnopqrstuvwxyz";
    ss="abcdefghijklmnopqrstuvwxyz";
    char ch,cc;

    cin>>str;

    for(int i=0;i<n;i++)
    {
       cin>>ch;
       cin>>cc;

       for(int j=0;j<26;j++)
       {
           if(stt[j]==ch)
           {
               stt[j]=cc;
           }

           else if(stt[j]==cc)
           {
               stt[j]=ch;
           }
       }
    }

    //cout<<stt<<endl;

    for(int i=0;i<str.size();i++)
    {
        cout<<stt[str[i]-97];

    }


}
