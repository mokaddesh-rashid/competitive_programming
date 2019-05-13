#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int value[n+1],i,top=n-1,bottom=0,a,b,c,x=0,y=0;

    for(i=0;i<n;i++)
        cin>>value[i];

    for(i=0;i<n;i++)
    {
        if(top==bottom)
            a=value[top];
        else if(value[top]>value[bottom])
        {
            a=value[top];
            top--;
        }
        else if(value[top]<value[bottom])
        {
            a=value[bottom];
            bottom++;
        }
        if(i%2==0)
           x=x+a;

        else
            y=y+a;

    }

    cout<<x<<' '<<y;
}
