#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;

    cin>>n;

    string str;

    cin>>str;

    int i,j,a=0,b=0,c,d,x=0,arr[3000+3]={0};


    for(i=0;i<str.size();i++)
    {
        if(str[i]=='R')
        {
            a=1;
            arr[i]++;
        }
         else if(str[i]=='L')
        {
            a=0;
        }
        else if(a==1)
            arr[i]++;

    }


    a=0;
    for(i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='L')
        {
            a=1;
            arr[i]++;
        }
         else if(str[i]=='R')
        {
            a=0;
        }
        else if(a==1)
            arr[i]++;

    }
    for(i=0;i<str.size();i++)
        {
            if(arr[i]==0)
                x++;
        }

    a=0;
    for(i=0;i<str.size();i++)
        {
            if(arr[i]==2)
                a++;
            else
            {
                if(a%2)
                    x++;
                a=0;
            }
        }
    cout<<x;


}
