#include<iostream>
#include<algorithm>

using namespace std;


void mergee(long long int got[],long long int arr[],long long int start,long long int mid,long long int endd)
{
  long long int n1,n2;

  n1=mid-start+1;
  n2=endd-mid;

  long long int f[n1+1],f_g[n1+1],s[n2+1],s_g[n2+1],i,j,k;

  for(i=0;i<max(n1,n2);i++)
   {

  if(i<n1)
    {

       f[i]=arr[start+i];
       f_g[i]=got[start+i];
    }

  if(i<n2)
    {
        s[i]=arr[mid+1+i];
        s_g[i]=got[mid+1+i];
    }
   }

    i=0;
    j=0;
    k=start;

    while(i<n1&&j<n2)
    {
        if(f[i]==s[j]&&f_g[i]<s_g[j])
      {
          arr[k]=f[i];
          got[k]=f_g[i];
          i++;
          k++;
      }
       else if(f[i]==s[j]&&f_g[i]>s_g[j])
      {
          arr[k]=s[j];
          got[k]=s_g[j];
          j++;
          k++;
      }
      else if(f[i]>s[j])
      {
          arr[k]=f[i];
          got[k]=f_g[i];
          i++;
          k++;
      }


      else
      {
          arr[k]=s[j];
          got[k]=s_g[j];
          j++;
          k++;


      }
    }


    while(i<n1)
    {
          arr[k]=f[i];
          got[k]=f_g[i];
          i++;
          k++;
    }

    while(j<n2)
    {
          arr[k]=s[j];
          got[k]=s_g[j];
          j++;
          k++;
    }


}

void divide(long long int got[],long long int arr[],long long int start,long long int endd)
{
    if(start<endd)
    {
        long long int mid=(start+endd)/2;

        divide(got,arr,start,mid);
        divide(got,arr,mid+1,endd);


        mergee(got,arr,start,mid,endd);
    }
}


int main()
{
    long long int n,r,avg,i,k=0;

    cin>>n>>k;


    long long int solve[n+1],time[n+1],x=0,a=0,b=0,c,y;

    for(i=0;i<n;i++)
     {
        cin>>solve[i]>>time[i];

     }
     a=x/n;

     divide(time,solve,0,n-1);

     x=time[k-1];
     y=solve[k-1];




      for(i=0;i<n;i++)
     {
        if(x==time[i]&&y==solve[i])
            b++;

     }

     cout<<b;





}
