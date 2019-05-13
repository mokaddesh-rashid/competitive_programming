#include<iostream>
#include<cstring>

using namespace std;

int main()
{
      int n,len,x,i,a,b,c,y,z,k,l,total=0;

      cin>>n;

      char pos[n+1],des[n+1];

      cin>>pos>>des;

      for(i=0;i<n;i++)
      {
          x=pos[i]-48;
          y=des[i]-48;
          z=0;
          k=x;
          l=y;
            while(k!=l)
          {
              k++;

              if(k==10)
                 k=0;
             // cout<<k<<endl;
              z++;
          }

         // cout<<endl<<endl;
          k=0;
           while(x!=y)
          {
              x--;
              k++;
              //cout<<x<<endl;
              if(x==-1&&x!=y)
                 x=9;


          }

          total+=min(k,z);



      }

      cout<<total;




}
