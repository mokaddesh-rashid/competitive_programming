#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[4];

    cin>>str;

    int len,x,i,b;

    len=strlen(str);

    if(len==1)
    {
        x=str[0]-48;
        //cout<<x;
        if(x==0)
            cout<<"zero";
        else if(x==1)
            cout<<"one";
        else if(x==2)
            cout<<"two";
        else if(x==3)
            cout<<"three";
         else if(x==4)
            cout<<"four";
         else if(x==5)
            cout<<"five";
         else if(x==6)
            cout<<"six";
         else if(x==7)
            cout<<"seven";
         else if(x==8)
            cout<<"eight";
         else if(x==9)
            cout<<"nine";

    }
    else if(len==2&&str[0]=='1')
    {
        x=str[1]-48;
        //cout<<x;
        if(x==0)
            cout<<"ten";
        else if(x==1)
            cout<<"eleven";
        else if(x==2)
            cout<<"twelve";
        else if(x==3)
            cout<<"thirteen";
         else if(x==4)
            cout<<"fourteen";
         else if(x==5)
            cout<<"fifteen";
         else if(x==6)
            cout<<"sixteen";
         else if(x==7)
            cout<<"seventeen";
         else if(x==8)
            cout<<"eighteen";
         else if(x==9)
            cout<<"nineteen";
    }
    else if(len==2)
    {
         x=str[0]-48;
        //cout<<x;
         if(x==2)
            cout<<"twenty";
        else if(x==3)
            cout<<"thirty";
         else if(x==4)
            cout<<"forty";
         else if(x==5)
            cout<<"fifty";
         else if(x==6)
            cout<<"sixty";
         else if(x==7)
            cout<<"seventy";
         else if(x==8)
            cout<<"eighty";
         else if(x==9)
            cout<<"ninety";


         x=str[1]-48;
       // cout<<x;

          if(x==1)
            cout<<'-'<<"one";
        else if(x==2)
            cout<<'-'<<"two";
        else if(x==3)
            cout<<'-'<<"three";
         else if(x==4)
            cout<<'-'<<"four";
         else if(x==5)
            cout<<'-'<<"five";
         else if(x==6)
            cout<<'-'<<"six";
         else if(x==7)
            cout<<'-'<<"seven";
         else if(x==8)
            cout<<'-'<<"eight";
         else if(x==9)
            cout<<'-'<<"nine";

    }
}
