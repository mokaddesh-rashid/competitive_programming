#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str[111];

    cin>>str;

    int len,n,i,a=0,x,b,ar[111];

    len=strlen(str);

    for(i=0;i<len;i+=2)
    {
        x=str[i]-48;
        ar[a]=x;
        a++;

       // cout<<x<<endl<<a<<endl;
    }

    for(i=0;i<a;i++)
        for(n=0;n<a;n++)
        {
            if(ar[i]<ar[n])
                swap(ar[n],ar[i]);
        }


     for(i=0;i<a;i++)
     {
         if(i==a-1)
            cout<<ar[i];
         else
         cout<<ar[i]<<'+';
     }
}
