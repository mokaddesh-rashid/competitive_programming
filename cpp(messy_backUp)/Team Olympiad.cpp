#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int math[n+1],physics[n+1],prog[n+1],i,x=0,y=0,z=0,a,b,c;

    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
        {
            math[x]=i;
            x++;
        }
        else if(a==2)
        {
            physics[y]=i;
            y++;
        }
        else if(a==3)
        {
            prog[z]=i;
            z++;
        }
    }
    x=min(x,y);
    x=min(x,z);

    cout<<x<<endl;

    for(i=0;i<x;i++)
        cout<<math[i]+1<<' '<<physics[i]+1<<' '<<prog[i]+1<<endl;
}
