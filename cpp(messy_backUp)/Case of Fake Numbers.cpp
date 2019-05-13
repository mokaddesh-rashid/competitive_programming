#include<iostream>

using namespace std;


int main()
{
    int N;

    cin>>N;

    int arr[N+1],i,a=0,b,c,d=0,e;


    for(i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    while(N*N>a)
    {
        c=0;
       for(i=0;i<N;i++)
       {
           if(i%2==0)
           {
               arr[i]=(arr[i]+1)%N;
           }

           else
           {
               arr[i]--;

               if(arr[i]==-1)
                arr[i]=N-1;
           }
       }
     if(arr[N-1]==N-1)
      for(i=0;i<N;i++)
    {
        if(arr[i]==i)
            c++;
        else
            break;
    }

    if(c==N)
       {
            d=1;
            break;
       }
    a++;


    }

    if(d==1)
        cout<<"Yes";

    else
        cout<<"No";
}
