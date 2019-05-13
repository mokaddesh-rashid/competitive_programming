#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

   string str,ans,chk;

   int n,i,j,x=0,a,b,c,y;

   cin>>n;

   cin>>str;

   ans=str;
   chk=str;

   while(x<n)
   {
       y=0;
       while(y<=9)
       {
           for(i=0;i<n;i++)
       {
           if(chk[i]=='0')
               chk[i]='1';

          else if(chk[i]=='1')
               chk[i]='2';

          else if(chk[i]=='2')
               chk[i]='3';

          else if(chk[i]=='3')
               chk[i]='4';

          else if(chk[i]=='4')
               chk[i]='5';

          else if(chk[i]=='5')
               chk[i]='6';

          else if(chk[i]=='6')
               chk[i]='7';

          else if(chk[i]=='7')
                chk[i]='8';

          else if(chk[i]=='8')
               chk[i]='9';

          else if(chk[i]=='9')
               chk[i]='0';

       }
       //cout<<chk<<endl;

          if(ans>chk)
          {
              ans=chk;
          }
          y++;
       }


       for(i=0;i<n;i++)
       {
          chk[(i+1)%n]=str[i];
       }
      // cout<<endl<<endl<<endl;
       str=chk;

       x++;
   }

   cout<<ans;




}

