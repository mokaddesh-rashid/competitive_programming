#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str="abcdefghijklmnopqrstuvwxyz";

    int n,x,i;

    cin>>n>>x;

    if(x>n||(x==1&&n>1))
        cout<<-1;
    else if(x==1)
    {
        for(i=0;i<n;i++)
            cout<<str[0];

    }
    else if(x==2)
    {
        //cout<<2;
        for(i=0;i<n;i++)
           {
               if(i%2)
                   cout<<str[1];
               else
                    cout<<str[0];

           }
    }
     else
    {

           for(i=0;i<n-x+2;i++)
           {
               if(i%2)
                   cout<<str[1];
               else
                    cout<<str[0];

           }
           for(i=0;i<x-2;i++)
           {
               cout<<str[i+2];

           }
    }


}
