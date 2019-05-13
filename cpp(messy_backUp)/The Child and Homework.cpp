#include<iostream>
#include<string>

using namespace std;

int main()
{
    string A,B,C,D;

    long long int a,b,c,d,x=0,ans=0;

    cin>>A>>B>>C>>D;

    a=A.size()-2;
    b=B.size()-2;
    c=C.size()-2;
    d=D.size()-2;

    //cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;

    if((a<=b/2&&a<=c/2&&a<=d/2)||(a>=b*2&&a>=c*2&&a>=d*2))
        {
            ans=1;
            x++;
        }

    if((b<=a/2&&b<=c/2&&b<=d/2)||(b>=a*2&&b>=c*2&&b>=d*2))
        {
            ans=2;
            x++;
        }

     if((c<=b/2&&c<=a/2&&c<=d/2)||(c>=b*2&&c>=a*2&&c>=d*2))
        {
            ans=3;
            x++;
        }

     if((d<=b/2&&d<=c/2&&d<=a/2)||(d>=b*2&&d>=c*2&&d>=a*2))
        {
            ans=4;
            x++;
        }

   // cout<<x<<endl;

      if(ans==1&&x==1)
        cout<<'A';
     else if(ans==2&&x==1)
        cout<<'B';
     else if(ans==3&&x==1)
        cout<<'C';
     else if(ans==4&&x==1)
        cout<<'D';
     else
        cout<<'C';




}

