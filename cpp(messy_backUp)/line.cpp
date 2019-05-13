#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

   long long int i,x=0,a,b=0,c=0,f=0,t=0,h=0;

    for(i=0;i<n;i++)
    {
        cin>>a;

      if(a==25)
         {
              x+=a;
              t++;
              //acout<<"a "<<a<<" b "<<b<<" x "<<x<<endl;
         }
      else if(a==50)
       {

           b=a-25;

         // cout<<"a "<<a<<" b "<<b<<" x "<<x<<f<<endl;
           if(b>x||t<=0)
            c=1;
           else
            x+=25;

            f++;
            t--;

       }

       else if(a==100)
       {

           b=a-25;

          // cout<<"a "<<a<<" b "<<b<<" x "<<x<<endl;
           if(b>x||(t<=2&&f<=0))
            c=1;
           else
            x+=25;

            f--;
            t--;
            h++;

       }
    }

    if(c==1)
        cout<<"NO";
    else
        cout<<"YES";
}
