#include<iostream>

using namespace std;

int main()
{
    long long int mag[4][4],i,n,a,b=0,x=0,maxx=0,y,z;


    for(i=0;i<3;i++)
        for(n=0;n<3;n++)
           cin>>mag[i][n];

    if(mag[0][0]!=0&&mag[1][1]!=0&&mag[2][2]!=0)
       {
            maxx=mag[0][0]+mag[1][1]+mag[2][2];
            b=1;
       }
    else if(mag[0][2]!=0&&mag[1][1]!=0&&mag[2][0]!=0)
       {
           maxx=mag[0][2]+mag[1][1]+mag[2][0];
           b=1;
       }
    else if(mag[0][0]==0&&mag[1][1]==0&&mag[2][2]==0)
       {

           x=mag[0][1]+mag[0][2];
           y=mag[1][0]+mag[1][2];
           z=mag[2][0]+mag[2][1];

           a=max(x,y);
           a=max(a,z);
           a++;

           x=a-x;
           y=a-y;
           z=a-z;

           //cout<<a<<' '<<x<<' '<<y<<' '<<z<<endl;

           while(x+y+z!=a)
           {
               a++;
               x++;
               y++;
               z++;
           }

        mag[0][0]=x;
        mag[1][1]=y;
        mag[2][2]=z;

       }
    else if(mag[0][2]==0&&mag[1][1]==0&&mag[2][0]==0)
       {
           x=mag[0][1]+mag[0][0];
           y=mag[1][0]+mag[1][2];
           z=mag[2][2]+mag[2][1];

           a=max(x,y);
           a=max(a,z);
           a++;

           x=a-x;
           y=a-y;
           z=a-z;

          // cout<<a<<' '<<x<<' '<<y<<' '<<z<<endl;

           while(x+y+z!=a)
           {
               a++;
               x++;
               y++;
               z++;
           }

         mag[0][2]=x;
         mag[1][1]=y;
         mag[2][0]=z;
       }

     for(i=0;i<3;i++)
        {
            x=0;
            a=0;
            for(n=0;n<3;n++)
               {
                  a+=mag[n][i];

                  if(mag[n][i]==0)
                    x=1;
               }

            maxx=max(a,maxx);
            if(x==0)
                b=1;


        }

     for(i=0;i<3;i++)
        {
            x=0;
            a=0;
            for(n=0;n<3;n++)
               {
                  a+=mag[i][n];

                  if(mag[i][n]==0)
                    x=1;
               }

            maxx=max(a,maxx);
            if(x==0)
                b=1;


        }


       if(b==1)
       {
            long long int y,z;

        for(i=0;i<3;i++)
        {
            x=0;
            a=0;
            for(n=0;n<3;n++)
               {
                  a+=mag[n][i];

                  if(mag[n][i]==0)
                   {
                      x++;
                      y=n;
                      z=i;
                   }
               }

           if(x==1)
           {
               mag[y][z]=maxx-a;
           }


        }

        for(i=0;i<3;i++)
        {
            x=0;
            a=0;
            for(n=0;n<3;n++)
               {
                  a+=mag[i][n];

                  if(mag[i][n]==0)
                   {
                      x++;
                      y=n;
                      z=i;
                   }
               }

           if(x==1)
           {
               mag[z][y]=maxx-a;
           }


        }

       }





    for(i=0;i<3;i++)
       {
          for(n=0;n<3;n++)
             cout<<mag[i][n]<<' ';

             cout<<endl;
       }






}
