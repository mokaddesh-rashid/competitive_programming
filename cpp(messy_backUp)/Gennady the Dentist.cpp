#include<iostream>


using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int n;

    cin>>n;

    int vi[n+1],di[n+1],pi[n+1],i,j,a,b=0,c=0,x=0,arr[n+1],k;


    for(i=0;i<n;i++)
    {
        cin>>vi[i]>>di[i]>>pi[i];
    }

    for(i=0;i<n;i++)
    {
       if(pi[i]-b>=0)
       {
           arr[x]=i+1;
           x++;

           j=i+1;
           a=vi[i];

           while(a>0&&j<n)
           {
               if(pi[j]-b>=0)
               {
                   pi[j]-=a;
                   a--;


                 if(pi[j]<0)
                 {

                     b+=di[j];


                 }
               }
               j++;
           }

       }
    }

    cout<<x<<endl;

    for(i=0;i<x;i++)
        cout<<arr[i]<<' ';


}
