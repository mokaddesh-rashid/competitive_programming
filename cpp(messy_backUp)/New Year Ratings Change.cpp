#include<iostream>

using namespace std;

int main()
{
    long long int n;

    cin>>n;


    long long int arr[n+1],next[n+1],i,use[10*10*10*10*10]={0},a,b;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        next[arr[i]]=arr[i]+1;
        use[arr[i]]++;
    }

    for(i=0;i<n;i++)
    {
       if(use[arr[i]]>1)
       {
           a=arr[i];
           b=a;
           use[arr[i]]--;
           while(use[a]==0)
           {
               a++;
           }
           arr[i]=a;
           use[a]++;
           next[b]=a;

       }
    }




}
