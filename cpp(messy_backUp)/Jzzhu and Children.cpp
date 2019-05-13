#include<iostream>

using namespace std;

int main()
{
    int n,m,i,x,a,b,c=0;

    cin>>n>>m;

    x=n;

    for(i=0;i<n;i++)
    {
        cin>>a;

        if(a>m)
        {
           b=a/m;

           if(a%m)
            b++;

           if(b>=c)
           {
               x=i+1;
               c=a/m;
               if(a%m)
                 c++;
           }


        }
    }
    cout<<x;
}
