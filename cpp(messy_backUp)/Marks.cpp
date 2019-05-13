#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,m,x,i,time=0;

    cin>>n>>m;

    char str[n+1][m+1],maxx[m+1];

     for(x=0;x<m;x++)
          {
            maxx[x]='1';//=max(str[i][m],maxx[x]);
          }


    for( i=0;i<n;i++)
       {
          cin>>str[i];

           for(x=0;x<m;x++)
          {
            maxx[x]=max(str[i][x],maxx[x]);
//cout<<maxx[x]<<' '<<str[i][x]<<endl;
          }


       }

        for( i=0;i<n;i++)
       {


           for(x=0;x<m;x++)
          {
           if(str[i][x]==maxx[x])
           {
               time++;
               break;
           }
          }


       }

       cout<<time;



}
