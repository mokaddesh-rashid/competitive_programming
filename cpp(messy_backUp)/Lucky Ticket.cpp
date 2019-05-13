#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    string str;

    cin>>n;
    cin>>str;

    int i,a,b,x=0,y=0,z=0,c;

    a=n/2;
    //cout<<a<<endl;
    for(i=0;i<n;i++)
    {
        b=str[i]-48;
       // cout<<b<<endl;
       if(b==4||b==7)
       {

           if(i<a)
           {
             x+=b;
            // cout<<a<<' '<<x<<endl;
           }
           else
           {
             y+=b;
             //cout<<a<<' '<<y<<endl;
           }
       }

       else
       {
           z=1;
           break;
       }
    }

    if(x==y&&z==0)
        cout<<"YES";
    else
        cout<<"NO";
}
