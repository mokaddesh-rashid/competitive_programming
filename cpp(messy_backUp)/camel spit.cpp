#include<iostream>

using namespace std;

int main()
{
    int pos[111],dis[111],i,n,a,b,c,x,m,y;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>pos[i]>>dis[i];
    }

    for(i=0;i<n;i++)
    {
        x=pos[i]+dis[i];

        for(m=0;m<n;m++)
        {
            if(m==i)
                continue;
            else if(x==pos[m])
            {
                 y=pos[m]+dis[m];
                 if(y==pos[i])
                   {
                    a=1;
                    break;
                   }
            }
        }
        if(a==1)
            break;
    }

    if(a==0)
        cout<<"NO";
    else if(a==1)
        cout<<"YES";
}
