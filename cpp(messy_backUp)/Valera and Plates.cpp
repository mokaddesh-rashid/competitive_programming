#include<iostream>

using namespace std;

int main()
{
    int n,b,p;

    cin>>n>>b>>p;

    int i,a,x=0,y,c,d,e;

    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
        {
            if(b>0)
                b--;

            else
              x++;

        }
        else if(a==2)
        {
            if(p>0)
                p--;

            else if(b>0)
                b--;
            else
                x++;

        }
    }

    cout<<x;


}
