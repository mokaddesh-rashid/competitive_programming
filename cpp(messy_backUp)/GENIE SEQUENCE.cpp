#include<iostream>

using namespace std;

int main()
{
   int t;

   cin>>t;

   while(t>0)
   {
        int N;

    cin>>N;

    int arr[N+1],i,a=0,b,c,d,x=0;
    int num[1111]={0};

    for(i=0;i<N;i++)
    {
        cin>>arr[i];
        num[arr[i]]++;

        if(arr[i]>=N)
            a=1;
    }

    if(a==0)
    {
        for(i=0;i<N;i++)
        {
            if(num[i]!=0)
            {
                num[i]--;
            }

            else if(num[N-i-1]!=0)
            {
                num[N-i-1]--;
            }
            else
                a=1;
        }
    }

    if(a==0)
        cout<<"YES\n";
    if(a==1)
        cout<<"NO\n";

        t--;
   }


}
