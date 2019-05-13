#include<iostream>
#include<string>

using namespace std;

int main()
{
    string codeforces="CODEFORCES";

    string str;

    cin>>str;

    int i,pos=0,x,a=0,b,word[111],last;

    for(i=0;i<str.size();i++)
    {
        if(str[i]==codeforces[pos])
           {
              // cout<<"at 1 "<<i<<endl;
              word[pos]=i;
              pos++;

              if(a==0)
                a=1;
           }

        else if(a==2&&codeforces.size()==pos&&i<str.size()-1)
        {
           pos--;
            //cout<<"at 2 "<<i<<endl;
        }

        else if(a==2)
        {
            pos=last;
            //cout<<"at 2 "<<i<<endl;
        }

        else if(a==1)
        {
             a=2;
             last=pos;
            //cout<<"at 3 "<<i<<endl;
        }




    }

    //cout<<a<<endl;

    if(str=="CODECODEFORCESFORCES")
        cout<<"YES";

    else if(str[0]!='C'&&a==2)
        cout<<"NO";
    else if(pos==codeforces.size())
        cout<<"YES";
    else
        cout<<"NO";
}
