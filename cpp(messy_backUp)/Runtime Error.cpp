#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
   int t;

   cin>>t;

   while(t>0)
   {
        int n,k;

        cin>>n>>k;

        int arr[n+1],time[100000+1]={0},maxx=-1,i,j,a,b,c,x=111111,y,d;

        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            a=arr[i];
            time[a]++;
        }


       for(i=0;i<n;i++)
        {
            if(arr[i]!=0&&k%arr[i]==0)
            {
                a=arr[i];
                b=k/arr[i];

            if(time[a]!=0&&time[b]!=0&&a!=b)
            {
                c=min(a,b);
                d=max(b,a);
                if(c<x)
                {
                    x=c;
                    y=d;
                }

                maxx=1;

            }
            else if(time[a]>1&&a==b)
            {
                c=min(a,b);
                d=max(b,a);
                if(c<x)
                {
                    x=c;
                    y=d;
                }
                maxx=1;

            }
            }

        }

        if(maxx==-1)
            cout<<-1;
        else
            cout<<x<<' '<<y;

        if(t>1)
            cout<<endl;







    t--;
   }



}
