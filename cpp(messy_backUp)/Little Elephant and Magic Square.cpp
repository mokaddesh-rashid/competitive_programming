#include<iostream>

using namespace std;

int main()
{
    long long int mag[4][4],i,n,a,b=0,x=0,maxx=0;


    for(i=0;i<3;i++)
        for(n=0;n<3;n++)
           cin>>mag[i][n];

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

    if(b!=1)
        maxx+=15;
    else if(b==1)
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
