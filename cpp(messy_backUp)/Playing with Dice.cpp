#include<iostream>

using namespace std;

int main()
{
    int a,b,c;

    cin>>a>>b;

    int i,n,wi=0,dr=0,lo=0,x,y;

    for(i=1;i<7;i++)
    {
        x=max(a-i,i-a);
        y=max(b-i,i-b);

        if(x==y)
            dr++;
        else if(x>y)
            wi++;

        else if(x<y)
            lo++;

    }

    cout<<lo<<' '<<dr<<' '<<wi;
}
