#include<iostream>
#include<string>


using namespace std;

int main()
{
    string str;

    cin>>str;

    int f=0,s=0,h=0,i,j=0,a=0,b,arr[str.size()+1],c,d;



    for(i=0;i<str.size();i++)
    {
        if(str[i]=='(')
            f++;
        else if(str[i]==')')
            s++;

        else if(str[i]=='#')
           {
               arr[a]=1;
               a++;
               s++;
               c=s;
               d=f;
           }

        if(s>f)
            j=1;
    }

    arr[a-1]=1+f-s;
    f=0;
    s=0;
    c=0;
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='(')
            f++;
        else if(str[i]==')')
            s++;

        else if(str[i]=='#')
           {
               s+=arr[c];
               c++;
           }

        if(s>f)
            j=1;
    }

    if(j==1)
        cout<<-1;
    else
        for(i=0;i<a;i++)
            cout<<arr[i]<<endl;


}
