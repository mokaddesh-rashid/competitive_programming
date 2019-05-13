#include<iostream>

using namespace std;

int main()
{
    int n,m;

    cin>>n;

    int arr[n+1],i,x=0,a,b,c,maxx=-1,t=0;

    for(i=0;i<n;i++)
        cin>>arr[i];

    cin>>m;

    int brr[m+1];

    for(i=0;i<m;i++)
    {
        cin>>brr[i];
    }


    for(i=0;i<n;i++)
    {
        for(x=0;x<m;x++)
        {
            if(brr[x]%arr[i]==0)
            {
                a=brr[x]/arr[i];

                if(maxx==-1)
                {
                    maxx=a;
                    t=1;
                }
                else if(maxx==a)
                {
                    t++;
                }
                else if(maxx<a)
                {
                    maxx=a;
                    t=1;
                }
            }
        }
    }

    cout<<t<<endl;


}
