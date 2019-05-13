#include<iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main()
{
    int arr[10*10*10*10*10*2]={0},i,j,prime[10*10*10*10*10*2],x=0,a,b,c,y,z,l,ans=10*10*10*10*10+1;


    for(i=2;i<10*10*10*10*10*2;i++)
    {
        if(arr[i]==0)
        {
            prime[x]=i;
            x++;
            j=i+i;

            while(j<10*10*10*10*10*2)
            {
                arr[j]=1;
                j+=i;
            }
        }
    }

    vector<int> v(prime,prime+x);
    vector<int>::iterator low,up;

   int n,m,start,mid,last;

    cin>>n>>m;

   int mat[n+1][m+1];

   for(i=0;i<n;i++)
   {
       c=0;
       for(j=0;j<m;j++)
       {
           cin>>a;

           if(a==1)
           {
               mat[i][j]=1;
               c+=1;
           }
           else if(arr[a]==0)
           {
               mat[i][j]=0;
           }
           else
           {
               low= lower_bound (v.begin(), v.end(), a);

               //cout<<prime[low- v.begin()]<<' '<<prime[low- v.begin()-1]<<endl;//<<' '<<prime[low- v.begin()+1]<<endl;
               y=prime[low- v.begin()]-a;
               //z=prime[low- v.begin()-1]-a;

                mat[i][j]=y;
              c+=y;

           }
       }
       ans=min(ans,c);
   }
   for(i=0;i<m;i++)
   {
       c=0;
       for(j=0;j<n;j++)
       {
           //cout<<mat[j][i]<<' ';
           c+=mat[j][i];
       }
       //cout<<endl;
       ans=min(ans,c);
   }

   cout<<ans;
}
