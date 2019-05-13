#include<iostream>

using namespace std;

int main()
{
    long long int n,v,i,x,a,b=0,d=0;

    cin>>n>>v;

    int pos[n+1],c=0;

    for(i=0;i<n;i++)
    {

        d=0;
        cin>>a;

        for(x=0;x<a;x++)
        {
            cin>>b;

            if(b<v&&d=0)
            {
                d=1;
                pos[c]=i;
                c++;

            }
        }
    }
    cout<<c<<endl;
    for(i=0;i<c;i++)
    {
        cout<<pos[i]+1<<' ';
    }
}
