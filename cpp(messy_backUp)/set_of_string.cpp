#include<iostream>
#include<string>


using namespace std;

int main()
{
    string str;
    int pos[27]={0},i,k,y=0;



    cin>>k>>str;

    for(i=0;i<str.size();i++)
    {
        int x=str[i]-97;
       pos[x]++;
    }
    for(i=0;i<26;i++)
    {
       if(pos[i]!=0)
          y++;


    }

    if(y<k)
        cout<<"NO";
    else
    {
        int dipos[26]={0};
        cout<<"YES"<<endl;
        for(i=0;i<str.size();i++)
    {
        int x=str[i]-97;
        if(k==1)
            cout<<str[i];
        else if(i==0&&k>1)
           {
                cout<<str[i];
                dipos[x]=1;
           }

       else if(str[i]==str[i-1]&&k>1||dipos[x]==1)
         cout<<str[i];
        else if(str[i]!=str[i-1]&&k>1)
        {
            cout<<endl;
            cout<<str[i];
            k--;
        }
    }
    }
}
