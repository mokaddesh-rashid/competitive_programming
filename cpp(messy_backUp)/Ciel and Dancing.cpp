#include<iostream>

using namespace std;

int main()
{
    int b,g;

    cin>>b>>g;

    int i,n,a,x,c;

    if(g!=0)
    cout<<min(b,g)+max(b,g)-1<<endl;

    if(g!=0)
     for(i=0;i<b;i++)
    {
        if(i==0)
        {
            x=1;
            while(x<=g)
            {
                cout<<1<<' '<<x<<endl;
                x++;
            }
        }

        else
            cout<<i+1<<' '<<1<<endl;
    }

    else
        cout<<0;
}
