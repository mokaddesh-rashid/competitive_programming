#include<iostream>
#include<string>

using namespace std;

int main()
{
    long long int n,m,i,ans=0,pre,a,x=0;
    char ch;

    cin>>n>>m;

    string str,check;

    cin>>str;


    for(i=0;i<n;i++)
    {
        while(str[i]=='.'&&str[i+1]=='.')
        {
            i++;
            ans++;
        }
    }

   // cout<<ans<<endl;


    for(i=0;i<m;i++)
    {
        a=0;
        cin>>x;
        cin>>ch;


         if(str[x-1]=='.'&&ch!='.'&&str[x]=='.'&&str[x-2]=='.')
           ans-=2;

         else if(str[x-1]=='.'&&ch!='.'&&str[x]=='.')
           ans--;
         else if(str[x-1]=='.'&&ch!='.'&&str[x-2]=='.')
           ans--;

         else if(str[x-1]!='.'&&ch=='.'&&str[x]=='.'&&str[x-2]=='.')
           ans+=2;

         else if(str[x-1]!='.'&&ch=='.'&&str[x]=='.')
           ans++;
         else if(str[x-1]!='.'&&ch=='.'&&str[x-2]=='.')
           ans++;

        if(ans<0)
            ans=0;


        str[x-1]=ch;

        //cout<<str<<endl;

     cout<<ans<<endl;


    }
}



