#include<iostream>

using namespace std;

int main()
{
    int n,m,k;

    cin>>n>>m>>k;

    int player[1111]={0},num[m+1],i,x,a,b,c=0,d,y,z,ar[1111]={0},p=0;

    for(i=0;i<=m;i++)
    {
        cin>>num[i];

        if(i==m)
        {
            a=num[i];
            for(x=a;x>0;x/=2)
         {
            ar[c]=x%2;
            c++;
         }
        }
    }

    for(i=0;i<m;i++)
    {
         y=0;
          for(x=n-1;x>=0;x--)
            {
               player[x]=0;
            }
          c=0;
          a=num[i];
            for(x=a;x>0;x/=2)
         {
            if(x%2==1)
              player[c]=1;

            c++;
         }

         for(x=n;x>=0;x--)
            {
                if(player[x]!=ar[x])
                     y++;
            }

           if(k>=y)
            p++;

    }

    cout<<p;
}
