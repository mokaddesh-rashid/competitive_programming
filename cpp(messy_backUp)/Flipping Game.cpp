#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int pos[n+1],i,x,a=0,b=0,c=0,zero[n+1],y=0,d,z=0;

    for(i=0;i<n;i++)
    {
        cin>>pos[i];
        if(pos[i]==1)
            z++;

    }

    for(i=0;i<n;i++)
    {
        d=n-1;

        while(d!=0)
        {
            c=0;

        for(x=0;x<n;x++)
        {
          if(x>=i&&x<=d)
        {
            if(pos[x]==0)
                  c++;
        }

        else if(pos[x]==1)
            c++;
        }

        y=max(y,c);
        d--;
        }
    }

    if(z==n)
        cout<<n-1;
    else
    cout<<y;


}
