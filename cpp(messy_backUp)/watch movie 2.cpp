#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str,ab,ba,ca,da;

    ab="AB";
    ba="BA";



    cin>>str;

    int i,n,a=0,b=0,c,d,x=0,y=0;

    for(i=0;i<str.size();i++)
    {
        ca.assign(str,i,2);

        if(i+2<str.size())
          da.assign(str,i,3);
        if(da=="ABA")
        {
           i+=2;
        }

        else if(ca==ab&&a==0)
        {
            x=1;
            a=1;
            i++;
        }
        else if(ca==ba&&b==0)
        {
            y=1;
            b=1;
            i++;
        }
    }

    if(x==1&y==1)
        cout<<"YES";
    else
        cout<<"NO";
}
