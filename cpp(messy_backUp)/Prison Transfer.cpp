#include<iostream>

using namespace std;

int main()
{
    int n,t,c;

    cin>>n>>t>>c;

    int crime[n+1],i,x=0,a,b,y,ans=0;

    for(i=0;i<n;i++)
    {
        cin>>crime[i];

        if(crime[i]<=t)
          {
                x++;
                if(x>=c)
                    ans++;
          }
        else if(crime[i]>t)
            x=0;
    }

    cout<<ans;

}
