#include<iostream>

using namespace std;

int main()
{
    int ar[123],i,n,a,b,c,d,x,m,z=1;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>ar[i];

    for(i=0;i<n;i++)
    {
        for(m=i+1;m<n;m++)
    {

        a=ar[i]+ar[m];
        // cout<<a<<endl;

        for(x=0;x<n;x++)
        {
            if(ar[x]==a)
            {
               //cout<<x+1<<' '<<max(ar[i],ar[m])<<' '<<min(ar[i],ar[m])<<endl;
                 cout<<x+1<<' '<<max(i,m)+1<<' '<<min(i,m)+1;
                 z=0;
                break;

            }
        }

        if(z==0)
        break;

    }
        if(z==0)
        break;
    }

    if(z!=0)
        cout<<-1;

}
