#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str,ab,ba,ca,da;

    ab="AB";
    ba="BA";



    cin>>str;

    int i,n,a=0,b=0,c=0,d,x=0,y=0;

    for(i=0;i<str.size();i++)
    {
        ca.assign(str,i,2);

        da.assign(str,i,3);
       // cout<<ca<<endl;

        if(da=="ABA")
        {
            c++;
            i+=2;
        }

       else if(ca==ab&&a==0)
        {
            x=1;
            i++;
            a=1;
        }
        else if(ca==ba&&b==0)
        {
            y=1;
            i++;
            b=1;
        }
    }

    if(x==1&y==1||c>1)
        cout<<"YES";
    else if(c>0&&(x==1||y==1))
        cout<<"YES";
    else
        cout<<"NO";
}
