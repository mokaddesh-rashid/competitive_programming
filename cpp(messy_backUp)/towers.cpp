#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    int n;

    cin>>n;


    int ar[n+1],i,a=0,b,x,y=0,d;

    for(i=0;i<n;i++)
    {
        cin>>ar[i];

    }
    d=n;
    for(i=0;i<n;i++,d--)
    for(x=i;x<d;x++)
    {
        if(ar[i]>ar[x])
            swap(ar[i],ar[x]);
        if(ar[d]<ar[x])
            swap(ar[d],ar[x]);
    }


    d=0;
    for(i=0;i<n;i++)
    {
        y=0;
        x=ar[i];
        while(ar[i]==x)
        {
            y++;
            //cout<<"yes";
            i++;
        }
        if(i!=n-1)
        i--;
        d=max(y,d);
        a++;
        cout<<a<<' '<<i+1<<endl;

    }

    cout<<d<<' '<<a;



}
