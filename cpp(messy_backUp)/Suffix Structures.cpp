#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s,t;

    cin>>s;
    cin>>t;

    int x=0,a=0,b=0,c=0,d,i,s_al[26];


    for(i=0;i<s.size();i++)
    {
        if(s[i]==t[x]&&x<t.size())
                x++;
    }

    if(x==t.size())
        cout<<"automaton";
    else
    {
        x=0;

    int pos=s.find(t[x]);

    while(pos!=string::npos)
    {
        s.erase(pos,1);
        //cout<<s<<endl;
        x++;
        pos=s.find(t[x]);

    }

    if(s.size()==0&&x==t.size())
        cout<<"array";
    else if(s.size()!=0&&x==t.size())
        cout<<"both";
    else
        cout<<"need tree";

    }







}
