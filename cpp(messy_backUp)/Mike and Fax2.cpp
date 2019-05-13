#include<iostream>

using namespace std;

int main()
{
    string str;

    int k,i,n,a,b=0,c,d=1;

    cin>>str>>k;

    a=str.size()/k;

    if(str.size()%k!=0)
        cout<<"NO";

    else
    {
        for(i=0;i<str.size();i+=a)
        {
            c=i;
       for(n=(a*d)-1;n>=i;n--)
       {

           if(str[c]!=str[n])
           {
                b=1;
                break;
           }

            c++;

       }
        d++;

       }

       if(b==0)
        cout<<"YES";
       else if(b==1)
        cout<<"NO";
    }


}
