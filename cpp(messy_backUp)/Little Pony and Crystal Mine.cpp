#include<iostream>

using namespace std;

int main()
{
    int x;

    cin>>x;

    int i,n,a,b,c=0;
    char str[111][111];

    a=x/2;
    b=x/2;

    for(n=0;n<x;n++)
    {
        for(i=0;i<x;i++)
    {
        if(i>=a&&i<=b)
            cout<<'D';

        else
           cout<<'*';

    }
       if(a==0)
            c=1;
        if(c==0)
        {
            a--;
            b++;
        }
        else if(c==1)
        {
            a++;
            b--;
        }
    cout<<endl;
    }



}
