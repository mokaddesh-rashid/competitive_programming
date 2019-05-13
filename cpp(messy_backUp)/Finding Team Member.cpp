#include<iostream>

using namespace std;

int main()
{
    long long int n;

    cin>>n;
    n*=2;

    long long int number[1000]={0},num[n+2][n+2],a,b,c,i,maxx,x,j,hm,l;

    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i-1;j++)
        {
            cin>>a;
            num[i][j]=a;
            num[j][i]=a;

        }
    }

    //cout<<endl<<endl;


     a=0;
     while(a<n)
     {
         for(i=1;i<=n;i++)
     {
         maxx=-1;


         if(number[i]==0)
         {
             for(j=1;j<=n;j++)
         {
             if(maxx==-1&&number[j]==0&&i!=j)
             {


                 hm=-1;
                 for(l=1;l<=n;l++)
                 {

             if(num[i][j]<num[j][l]&&number[l]==0&&l!=j)
             {

                hm=0;

             }



              }
                if(hm==-1)
                {
                    maxx=num[i][j];
                    x=j;
                }


             }

             else if(maxx<num[i][j]&&number[j]==0&&i!=j)
             {
                  hm=-1;
                 for(l=1;l<=n;l++)
                 {

             if(num[i][j]<num[j][l]&&number[l]==0&&l!=j)
             {

                hm=0;

             }



              }
                 if(hm==-1)
                {
                    maxx=num[i][j];
                    x=j;
                }
             }
         }

         if(maxx!=-1)
         {
             number[i]=x;
             number[x]=i;
             a+=2;
         }

         }
     }
     }

     for(i=1;i<=n;i++)
          cout<<number[i]<<' ';
}
