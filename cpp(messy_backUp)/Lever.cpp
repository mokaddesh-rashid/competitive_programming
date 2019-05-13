#include<iostream>
#include<string>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int a=0,b=0,x=0,y=0,i,j,p,l=0,r=0,c;

    string str;

    cin>>str;

     long long int arr[str.size()+1],krr[str.size()+1];



    for(i=0;i<str.size();i++)
    {
        if(str[i]=='^')
            x++;
        else if(x==0)
        {
           if(str[i]=='=')
                arr[a]=0;
           else
           {
               arr[a]=str[i]-48;
           }
           a++;
        }
        else if(x==1)
        {
            if(str[i]=='=')
                krr[b]=0;
           else
           {
               krr[b]=str[i]-48;
           }
           b++;

        }
    }
    c=1;
    for(i=a-1;i>=0;i--,c++)
    {
        l=l+(arr[i]*c);
    }
    c=1;
    for(i=0;i<b;i++,c++)
    {
        r=r+(krr[i]*c);
    }

    if(l==r)
        cout<<"balance";
    else if(l>r)
        cout<<"left";
    else
        cout<<"right";


}
