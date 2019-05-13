#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int r,c;

    cin>>r>>c;

    char str[r+1][c+1],ch;

     int i,n,x=0,a,b,s=0;

   for(i=0;i<r;i++)
     cin>>str[i];

   for(i=0;i<r;i++)
   {
       s=0;
       for(n=0;n<c;n++)
       {
           if(str[i][n]=='S')
            s=1;
       }

       if(s==0)
       {
          for(n=0;n<c;n++)
       {
           if(str[i][n]=='.')
           {
               str[i][n]='E';
               x++;
           }
       }
       }
   }

  for(i=0;i<c;i++)
   {
       s=0;
       for(n=0;n<r;n++)
       {
           if(str[n][i]=='S')
            s=1;
       }

       if(s==0)
       {
          for(n=0;n<r;n++)
       {
           if(str[n][i]=='.')
           {
               str[n][i]='E';
               x++;
           }
       }
       }
   }

   cout<<x;
}
